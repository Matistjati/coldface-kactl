/**
 * Author: Joshua Andersson
 * Description: Each node has weight. Select max weight subset
 * s.t. no edge goes from the subset to non-subset node. Edges
 * may go non-subset to subset. For each node $u$ with non-negative weight $w$,
 * add edge $s \rightarrow u$ with capacity $w$. For each node $u$ with negative weight $x$,
 * add edge $u \rightarrow t$ with capacity $-x$. Answer is sum of all positive weights
 * minus min $s-t$ cut.
 *
 */