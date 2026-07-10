/**
 * Author: Jeremy Lim, Joshua Andersson
 * Date: 2026-07-09
 * License: CC0
 * Source: https://github.com/scipy/scipy/blob/main/scipy/optimize/rectangular_lsap/rectangular_lsap.cpp
 * Description: Given a weighted bipartite graph, matches every node on
 * the left with a node on the right such that no
 * nodes are in two matchings and the sum of the edge weights is minimal. Takes
 * cost[N][M], where cost[i][j] = cost for L[i] to be matched with R[j], and
 * returns (min cost, match), where L[i] is matched with
 * R[match[i]]. Negate costs for max cost. Requires $N \le M$.
 * Time: O(N^2M)
 * Status: Tested on kattis:cordonbleu, kattis:engaging, stress-tested
 */
#pragma once

template <typename T> pair<T, vector<int>>
weighted_matching(vector<vector<T>> &C) {
	int i = sz(C), m = i ? sz(C[0]) : 0, c, j, s, r;
	vector<T> dist(m), potential(m);
	vi row_match(i), col_match(m, -1), cols(m), prev(m);
	T d, nd, cost = 0;
	while (i--) {
		rep(c,0,m) dist[c] = C[i][c], cols[c] = c, prev[c] = i;
		for (s = 0;;) {
			rep(j,s,m) {
				c = cols[j], nd = dist[c] - potential[c];
				if (j == s || d > nd) d = nd, swap(cols[s], cols[j]);
			}
			if (!~(r = col_match[c = cols[s++]])) break;
			rep(j,0,m) if (dist[j] > (nd = C[r][j]-C[r][c]+dist[c]))
				dist[j] = nd, prev[j] = r;
		}
		for (cost += dist[c]; s--;)
			j = cols[s], potential[j] = dist[j] - d;
		for (; r != i; swap(c, row_match[r]))
			r = col_match[c] = prev[c];
	}
	return {cost, row_match};
}
