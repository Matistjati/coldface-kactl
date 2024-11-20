/**
 * Author: Joshua Andersson
 * Description: Split each node into in-node and out-node.
 * Add edge from every out-node to in-node if edge exists.
 * Min path cover is n-max matching out nodes -> in nodes. \\
 * General path cover: if every node can be used multiple times,
 * do same as before, but add edge to all
 * nodes in transitive closure. \\
 * Max antichain: largest subset of nodes in DAG where every pair
 * of nodes are incomparable pairwise. Max size=min general path cover. \\
 * Partition graph into disjoint cycles: think matching.
 * If everything shits itself, you have lower bound circulation.
 * 
 *
 */