#include <bits/stdc++.h>
using namespace std;

// problem is to mark the entire row and column of the elemnt which turns out to be zero.

// brute force.
void markRow(vector<vector<int>> &v, int i)
{
    for (size_t j = 0; j < v.size(); j++)
    {
        if (v[i][j] != 0)
            v[i][j] = -1;
    }
}
void markCol(vector<vector<int>> &v, int j)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        if (v[i][j] != 0)
            v[i][j] = -1;
    }
}
void markZeros(vector<vector<int>> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            if (v[i][j] == 0)
            {
                markRow(v, i);
                markCol(v, j);
            }
        }
    }
    for (size_t i = 0; i < v.size(); i++){
        for (size_t j = 0; j < v.size(); j++){
            if(v[i][j] == -1)
                v[i][j] = 0;
        }
    }
}


// better solutin where the time is nearlky reduced to n^2
void markZerosB(vector<vector<int>> &v){
    vector<bool> row(v.size(), false), col(v.size(), false);
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            if(v[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
        
    }

    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v.size(); j++)
        {
            if(row[i] || col[j])
                v[i][j] = 0;
        }
        
    }
}

// optimal appraoch where we don't use space itself
void markZerosO(vector<vector<int>>& v){
    int col0 = 1;
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[0].size(); j++)
        {
            if(v[i][j] == 0){
                v[0][j] = 0;
                if(j)
                v[i][0] = 0;
                else
                    col0 = 0;
            }
        }
        
    }

    for (size_t i = 1; i < v.size(); i++)
    {
        for (size_t j = 1; j < v[0].size(); j++)
        {
            if(v[i][j]){
                if(!v[0][j] || !v[i][0])
                    v[i][j] = 0;
            }
        }
    }
    if(!v[0][0]){

        for (size_t j = 0; j < v.size(); j++)
        {
            v[0][j] = 0;
        }
    }
    if(!col0){
        for (size_t i = 0; i < v.size(); i++)
        {
            v[i][0] = 0;
        }
        
    }
}

void display(vector<vector<int>> &v)
{
    for (auto it : v)
    {
        for (auto el : it)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            v[i][j] = ele;
        }
    }
    // markZeros(v);
    // cout << endl;
    // display(v);
    cout << endl;
    markZerosO(v);
    display(v);
    return 0;
}