/**
 * Author: USACO guide
 * Date: 2024-10-27
 * License: idk
 * Source: * Source: https://usaco.guide/adv/BCC-2CC?lang=cpp
 * Description: Finds all biconnected components in an undirected graph, stored
 * in comps. If you remove one node in any BCC, it will still be connected.
 * Articulation points/cut vertices are stored in is\_cutvertex.
 * Time: O(E + V)
 * Status: tested on CSES Necessary Cities and Forbidden Cities
 */
#pragma once

vector<vector<int>> comps;
vi is_cutvertex, low, num, stk;
void dfs(int u, int p, int& timer, vvi& adj) {
	num[u] = low[u] = ++timer;
	stk.push_back(u);
	for (int e : adj[u]) if (e != p) {
		if (num[e]) low[u] = min(low[u], num[e]);
		else {
			dfs(e, u, timer, adj);
			low[u] = min(low[u], low[e]);
			if (low[e] < num[u]) continue;
			is_cutvertex[u] = (num[u] > 1 || num[e] > 2);
			comps.push_back({ u });
			while (comps.back().back() != e) {
				comps.back().push_back(stk.back());
				stk.pop_back();
			}
		}
	}
};

void bcc(vvi& adj) {
	is_cutvertex.assign(sz(adj), 0);
	num.assign(sz(adj), 0);
	low.assign(sz(adj), 0);
	int timer = 0;
	rep(i, 0, sz(adj)) {
		if (!num[i]) dfs(i, i, timer, adj);
	}
}
