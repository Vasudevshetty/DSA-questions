#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matToList(const vector<vector<int>> &mat)
{
    vector<vector<int>> list(mat.size());

    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            if (mat[i][j] != 0)
                list[i].push_back(j);
        }
    }
    return list;
}

vector<vector<int>> listToMat(const vector<vector<int>> &list)
{
    vector<vector<int>> mat(list.size(), vector<int>(list.size(), 0));

    for (size_t i = 0; i < list.size(); i++){
        for(int it : list[i]){
            mat[i][it] = 1;
            mat[it][i] = 1;
        }
    }
    return mat;
}

vector<vector<int>> inputMat(int vertex)
{
    vector<vector<int>> mat(vertex + 1, vector<int>(vertex + 1, 0));
    cout << "Please enter the adjacency matrix representation of the graph.\n";
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
            cin >> mat[i][j];
    }
    return mat;
}

vector<vector<int>> inputList(int vertex, int edges)
{
    vector<vector<int>> list(vertex + 1);

    cout << "Please enter the adjacency list(edges) representation of the graph.\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
    return list;
}

void displayMat(const vector<vector<int>> &mat)
{
    cout << "The graph represented in adjacency matrix is\n"; 
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void displayList(const vector<vector<int>> &list)
{
    cout << "The graph represeneted in adjacency list is, " << endl;
    for (size_t i = 0; i < list.size(); i++)
    {
        cout << "Vertex " << i << " : ";
        for (int it : list[i])
            cout << it << " ";
        cout << endl;
    }
}

int main()
{
    int vertex, edges;
    cin >> vertex >> edges;
    displayList(matToList(inputMat(vertex)));
    displayMat(listToMat(inputList(vertex, edges)));
    return 0;
}

// a lot of code, should refactor a bit and revisite a bit to make my leetcode profile robust.
