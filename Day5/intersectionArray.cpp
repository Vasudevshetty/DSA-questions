#include <bits/stdc++.h>
using namespace std;

// function to find the intersection of two arrays.
vector<int> intersection(vector<int> a, vector<int> b)
{
    vector<int> vis(b.size(), 0);
    vector<int> ans;
    for (size_t i = 0; i < a.size(); i++)
    {
        for (size_t j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if (b[j] > a[i])
                break;
        }
    }
    return ans;
}

// optimal solution
set<int> intersectionO(vector<int> a, vector<int> b)
{
    set<int> ans;
    size_t i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] > b[j])
            j++;
        else if (a[i] < b[j])
            i++;
        else
        {
            ans.insert(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a, b;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        a.push_back(ele);
    }
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        b.push_back(ele);
    }

    set<int> ans = intersectionO(a, b);
    for (auto it : ans)
        cout << it << " ";

    return 0;
}
