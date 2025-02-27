/**
 * Author: Joshua Andersson
 * Date: 2025-02-27
 * License: CC0
 * Source: me
 * Description: Segment tree that can add to intervals and query their sum. 
 * Can handle N=Q=$10^6$ or N=$2 \cdot 10^5$, Q=$2 \cdot 10^6$ in one second on Kattis.
 * To modify, change put\_node and the end of query and add. For most general, one put\_node
 * per update kind, put\_node calls each one in correct order.
 * Time: O(\log N).
 * Usage: Tree tree(N);
 * tree.add(1,0,N-1,l,r,v);
 * Status: stress-tested a bit
 */
#pragma once

struct Tree { // range add, range sum
    vi tree, lazy;
    Tree(int n) : tree(n * 4), lazy(n * 4) {}
    void put_node(int x, int l, int r, int v) {
        tree[x] += v * (r - l + 1);
        lazy[x] += v;
    }
    void push(int x, int l, int r) {
        int mid = (l + r) / 2;
        put_node(x * 2, l, mid, lazy[x]);
        put_node(x * 2 + 1, mid + 1, r, lazy[x]);
        lazy[x] = 0;
    }
    // add v to [l,r]. call add(1,0,n-1,...)
    void add(int x, int l, int r, int ql, int qr, int v) {
        if (l > qr || r < ql) return;
        if (l >= ql && r <= qr) return put_node(x, l, r, v);
        push(x, l, r);
        int mid = (l + r) / 2;
        add(x * 2, l, mid, ql, qr, v);
        add(x * 2 + 1, mid + 1, r, ql, qr, v);
        tree[x] = tree[x * 2] + tree[x * 2 + 1];
    }
    // sum [l,r]. call query(1,0,n-1,...)
    int query(int x, int l, int r, int ql, int qr) {
        if (l > qr || r < ql) return 0;
        if (l >= ql && r <= qr) return tree[x];
        push(x, l, r);
        int mid = (l + r) / 2;
        return query(x * 2, l, mid, ql, qr) +
            query(x * 2 + 1, mid + 1, r, ql, qr);
    }
};
