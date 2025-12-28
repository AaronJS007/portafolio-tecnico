#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Fenwick2d
{
    vector<vector<int>> bit;
    int n, m;
    Fenwick2d(int n, int m) : n(n), m(m), bit(n, vector<int>(m)) {}
    int get(int x, int y)
    {
        int s = 0;
        for (int i = x; i > 0; i &= i - 1)
            for (int j = y; j > 0; j &= j - 1)
                s += bit[i - 1][j - 1];
        return s;
    }
    void add(int x, int y, int v)
    {
        for (int i = x; i < n; i |= i + 1)
            for (int j = y; j < m; j |= j + 1)
                bit[i][j] += v;
    }
};