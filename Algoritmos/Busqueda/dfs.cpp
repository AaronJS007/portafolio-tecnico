#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define ii pair<int, int>
#define vii vector<pair<int, int>>
const int INF = 1e9;

void DFS_visit(int v, vvi &adj, vector<bool> &visited)
{
    visited[v] = true;
    for (int u : adj[v])
    {
        if (!visited[u])
        {
            DFS_visit(u, adj,
                      visited);
        }
    }
}
void DFS(int start, vvi &adj)
{
    int V = adj.size();
    vector<bool> visited(V, false);
    DFS_visit(start, adj, visited);
}