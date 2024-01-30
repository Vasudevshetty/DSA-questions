#include <bits/stdc++.h>
using namespace std;

void spiralPrint(vector<vector<int>> &mat)
{
    int left = 0, right = mat.size() - 1, bottom = mat.size() - 1, top = 0;
    while (left <= right && top <= bottom)
    {
        for (int i = left; i <= right; i++)
            cout << mat[top][i] << " ";
        top++;
        for (int i = top; i <= bottom; i++)
            cout << mat[i][right] << " ";
        right--;
        if(top <= bottom)
        for (int i = right; i >= left; i--)
            cout << mat[bottom][i] << " ";
        bottom--;
        if(right <= left)
        for (int i = bottom; i >= top; i--)
            cout << mat[i][left] << " ";
        left++;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;
            mat[i][j] = ele;
        }
    }
    spiralPrint(mat);
    return 0;
}