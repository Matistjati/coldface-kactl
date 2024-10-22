/**
 * Author: Joshua Andersson
 * Date: 2024-10-21
 * Source: https://courses.grainger.illinois.edu/cs498dl1/sp2015/notes/25-maxflowext.pdf
 * Description: Given a flow network with upper and lower bounds on edges, finds 
 * a feasible flow assignment if one exists. Combine with binary search for min
 * flow satisfying demands
 * Time: One max-flow call.
 * Status: Tested on some problems
 */
#pragma once

struct edge {
	int from, to, lo, hi;
};
typedef PushRelabel flowAlgorithm;

flowAlgorithm* lowerbound_flow(vector<edge>& edges, int n,
					int source, int sink, int capacity=inf) {
	flowAlgorithm* flow = new flowAlgorithm(n + 2);
	vi outflow(n), inflow(n);
	repe(e, edges) {
		outflow[e.from] += e.lo;
		inflow[e.to] += e.lo;
		flow->addEdge(e.from, e.to, e.hi - e.lo);
	}
	rep(i, n) {
		flow->addEdge(n, i, inflow[i]);
		flow->addEdge(i, n+1, outflow[i]);
	}
	flow->addEdge(sink, source, capacity);

	return flow->calc(n,n+1)==accumulate(all(outflow),0LL)
		? flow : nullptr;
}

