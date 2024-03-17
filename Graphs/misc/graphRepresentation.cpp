#include <bits/stdc++.h>
using namespace std;

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex + 1, vector<int>(edges + 1, 0)); // adj matrix
    vector<vector<int>> graphList(vertex + 1);                        // adj list
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        /*
            graph[u][v] = graph[v][u] = 1; // to store the adj matrix
        */

        graph[u].push_back(v); // to store the adj list
        graph[v].push_back(u);
    }
    return 0;
}