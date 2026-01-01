#include <iostream> 
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>  // Para std::min y std::max si los usas directamente
#include <climits>    // Para INT_MAX, INT_MIN
#include <iostream>   // Para cout, si lo usas
#define operation min // or max
const int INF = INT_MAX;
#define NEUTRAL INF   // or -INF
using namespace std;
struct STree
{ // segment tree for min over integers
    vector<int> st;
    int n;
    STree(int n) : st(4 * n + 5, NEUTRAL), n(n) {}
    void init(int k, int s, int e, int *a)
    {
        if (s + 1 == e)
        {
            st[k] = a[s];
            return;
        }
        int m = (s + e) / 2;
        init(2 * k, s, m, a);
        init(2 * k + 1, m, e, a);
        st[k] = operation(st[2 * k], st[2 * k + 1]);
    }
    void update(int k, int s, int e, int p, int v)
    {
        if (s + 1 == e)
        {
            st[k] = v;
            return;
        }
        int m = (s + e) / 2;
        if (p < m)
            update(2 * k, s, m, p, v);
        else
            update(2 * k + 1, m, e, p, v);
        st[k] = operation(st[2 * k], st[2 * k + 1]);
    }
    int query(int k, int s, int e, int a, int b)
    {
        if (s >= b || e <= a)
            return NEUTRAL;
        if (s >= a && e <= b)
            return st[k];
        int m = (s + e) / 2;
        return operation(query(2 * k, s, m, a, b), query(2 * k + 1, m, e, a, b));
    }
    void init(int *a) { init(1, 0, n, a); }
    void update(int p, int v) { update(1, 0, n, p, v); }
    int query(int a, int b) { return query(1, 0, n, a, b); }
}; // usage: STree rmq(n);rmq.init(x);rmq.update(i,v);rmq.query(s,e);