/**
 * Author: Joshua Andersson
 * Date: 2024-10-2s7
 * License: CC0
 * Source: https://en.wikipedia.org/wiki/Biconnected_component
 * Description: returns a list of all nodes in an undirected graph that
 *  are articulation points in sorted. Handles multiple components
 * Time: O(E + V)
 * Status: tested on CSES Necessary Cities
 */
#pragma once

vi depth, ap, lo;
int dfs(int u, int p, vvi& adj) {
	lo[u] = depth[u];
	int cc = 0;
	for (int e : adj[u]) if (e != p) {
		if (depth[e] == -1) {
			cc++;
			depth[e] = depth[u] + 1;
			dfs(e, u, adj);
			if (lo[e] >= depth[u]) ap[u] = 1;
			lo[u] = min(lo[u], lo[e]);
		}
		else lo[u] = min(lo[u], depth[e]);
	}
	return cc;
}

vi articulation_points(vvi& adj) {
	ap.assign(sz(adj), 0);
	lo.assign(sz(adj), 0);
	depth.resize(sz(adj), -1);
	rep(i, sz(adj)) if (depth[i] == -1) {
		depth[i] = 0;
		ap[i] = dfs(i, i, adj) > 1;
	}
	vi ret;
	rep(i, sz(adj)) if (ap[i]) ret.push_back(i);
	return ret;
}
