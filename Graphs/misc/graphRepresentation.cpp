#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &mat){
    for (size_t i = 1; i < mat.size(); i++){
        for (size_t j = 1; j < mat[i].size(); j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int vertex, edges;
    cin >> vertex >> edges;
    vector<vector<int>> graph(vertex + 1, vector<int>(vertex + 1, 0));
    for (int i = 0; i < edges; i++){
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
    }
        display(graph);
    return 0;
}