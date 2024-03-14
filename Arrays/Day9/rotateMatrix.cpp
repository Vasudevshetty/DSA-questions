#include<bits/stdc++.h>
using namespace std;

// the question is to find the ratatoed matrix by 90deg.

void display(vector<vector<int>> &mat){
    for(auto it: mat){
        for(auto ele: it)
            cout << ele << " ";
        cout << endl;
    }  
}

// the brute force where you find the exact postiion of the element to be fitted in, time and sapce O(n^2)
void rotate(vector<vector<int>> &mat){
    vector<vector<int>> rMat(mat.size(), vector<int>(mat.size()));
    for (size_t i = 0; i < mat.size(); i++){
        for (size_t j = 0; j < mat[0].size(); j++){
            rMat[j][mat.size() - 1 - i] = mat[i][j];
        }
    }
    display(mat);
}

// the optimal appraoch is to find the transpose and reverse all the rows of the matrix.
void rotateO(vector<vector<int>> &mat){
    for (size_t i = 0; i < mat.size(); i++){
        for (size_t j = i + 1; j < mat.size(); j++){
            if(i!=j)
                swap(mat[i][j], mat[j][i]);
        }
    }
    for(auto it: mat)
        reverse(it.begin(), it.end());
    display(mat);
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int ele;
            cin >> ele;
            v[i][j] = ele;
        }
    }
    rotateO(v);
    return 0;
}