/**
 * Author: USACO guide
 * Date: 2024-10-27
 * License: idk
 * Source: https://usaco.guide/adv/BCC-2CC?lang=cpp
 * Description: A graph with a vertex for each cut vertex and
 * each node-biconnected-component. These are joined if they have any
 * edge in the original graph. Is always a tree
 * Usage: bcc(adj);
 * vvi tree_adj = block_cut_tree();
 * Time: O(E + V)
 * Status: tested on CSES Necessary Cities and Forbidden Cities
 */
#pragma once

#include "NodeBiconnectedComponents.h"

vi which_block;
vvi block_cut_tree() {
	int n = sz(is_cutvertex);
	which_block.resize(n, -1);
	vector<vector<int>> block_adj(1);
	int node_id = 0;
	rep(i,0,n) {
		if (!is_cutvertex[i]) continue;
		which_block[i] = node_id++;
		block_adj.push_back({});
	}

	for (auto& comp : comps) {
		int node = node_id++;
		block_adj.push_back({});
		for (int u : comp) {
			if (!is_cutvertex[u]) which_block[u] = node;
			else {
				block_adj[node].push_back(which_block[u]);
				block_adj[which_block[u]].push_back(node);
			}
		}
	}
	return block_adj;
}