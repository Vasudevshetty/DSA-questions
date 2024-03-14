#include <bits/stdc++.h>
using namespace std;

// finding the next permutation of the given set of numbers.
// next permuataion stands for the sorted (dictonary wise permuattion) of the given set of numbers.

// optimal appraoch is.
void nextPerm(vector<int> &v)
{
    int idx = -1, n = v.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (v[i + 1] > v[i])
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
        reverse(v.begin(), v.end());
    else
    {

        for (int i = n - 1; i > idx; i--)
        {
            if (v[i] > v[idx])
            {
                swap(v[i], v[idx]);
                break;
            }
        }
        reverse(v.begin() + idx + 1, v.end());
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    nextPerm(v);
    for (auto ele : v)
        cout << ele << " ";
    next_permutation(v.begin(), v.end()); // this is the better appraoch..
    cout << endl;
    for (auto ele : v)
        cout << ele << " ";
    return 0;
}