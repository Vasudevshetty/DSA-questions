#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>> &graph, int startingVertex)
{
    vector<int> traversal;
    vector<bool> visited(graph.size() + 1, false);

    queue<int> que;

    que.push(startingVertex);
    visited[startingVertex] = true;

    while (!que.empty())
    {
        int vertex = que.front();
        que.pop();
        traversal.push_back(vertex);

        for (int it : graph[vertex])
        {
            if (!visited[it])
            {
                visited[it] = true;
                que.push(it);
            }
        }
    }
    return traversal;
}

vector<int> dfs(vector<vector<int>> &graph, int startingVertex)
{
    vector<int> traversal;
    vector<bool> visited(graph.size() + 1, false);

    stack<int> stack;

    stack.push(startingVertex);
    visited[startingVertex] = true;

    while (!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();
        traversal.push_back(vertex);

        for (int it : graph[vertex])
        {
            if (!visited[it])
            {
                visited[it] = true;
                stack.push(it);
            }
        }
    }
    return traversal;
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;

    vector<vector<int>> graph(vertex + 1);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int startingVertex;
    cin >> startingVertex;

    vector<bool> visited(vertex + 1, false);

    int count = 0;
    for (int i = 1; i <= vertex; i++)
    {

        if (!visited[i])
        {
            for (int it : dfs(graph, i))
            {
                visited[it] = true;
                cout << it << " ";
            }
            count++;
        }
    }
    cout << endl;
    cout << count << endl;
    return 0;
}