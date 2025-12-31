#include <iostream>
#include <bits/stdc++.h>
#include "union_fine.h"
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;
struct Ar
{
    int a, b, w;
    bool operator<(const Ar &other) const
    {
        return w < other.w;
    }
};
long long kruskal(int n, vector<vii> &G)
{
    vector<Ar> E;
    // Extrae aristas de la lista de adyacencia G
    for (int i = 0; i < n; i++)
    {
        for (auto &vecino : G[i])
        {
            int w = vecino.first;
            int j = vecino.second;
            // Evita duplicados agregando solo cuando i < j
            if (i < j)
            {
                E.push_back({i, j, w});
            }
        }
    }
    long long cost = 0;
    sort(E.begin(), E.end());
    UnionFind uf(n);
    for (const Ar &arista : E)
    {
        if (!uf.isSameSet(arista.a, arista.b))
        {
            uf.unionSet(arista.a, arista.b);
            cost += arista.w;
        }
    }
    return cost;
}
