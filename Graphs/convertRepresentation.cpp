#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> inputMat(int vertex, int edges){
    vector<vector<int>> mat(vertex + 1, vector<int>(edges + 1, 0));
    for (size_t i = 1; i < mat.size(); i++)
    {
        for (size_t j = 1; j < mat[i].size(); j++)
            cin >> mat[i][j];
    }
    return mat;
}

vector<vector<int>> inputList(int vertex, int edges){
    vector<vector<int>> list(vertex + 1);

    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;

        list[u].push_back(v);
        list[v].push_back(u);
    }
    return list;
}

void displayMat(const vector<vector<int>>& mat){
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
}

void displayList(const vector<vector<int>> &list){
    for (size_t i = 0; i < list.size(); i++){
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
    return 0;
}