/**
 * Author: Joshua Andersson
 * Date: 2024-02-06
 * Source: Folklore
 * Description: Gives for every node:
 * which centroid is my parent (par),
 * and which centroids are my children.
 * par[root]=-1
 * Time: $O(N \log N)$, centroid tree has $\log N$ depth
 * Status: Tested
*/

struct Centroid {
    vector<vi> adj, children;
    vi cnt, par;
    Centroid(const vector<vi>& adj) : adj(adj),
        children(sz(adj)), cnt(sz(adj),-1), par(sz(adj),-1) {
        dfs(0, -1);
    }
    void calc_sz(int u, int p) {
        cnt[u] = 1;
        for (int e : adj[u])
            if (e != p) calc_sz(e, u), cnt[u] += cnt[e];
    }
    int find_centroid(int u, int p, int n) {
        for (int e : adj[u])
            if (e != p && cnt[e] > n / 2)
                return find_centroid(e, u, n);
        return u;
    }
    void dfs(int u, int p) {
        calc_sz(u, -1);
        u = find_centroid(u, u, cnt[u]);
        par[u] = p;
        if (p!=-1) children[p].push_back(u);
        for (int e : adj[u]) {
            iter_swap(find(all(adj[e]), u), rbegin(adj[e]));
            adj[e].pop_back();
            dfs(e, u);
        }
    }
};
