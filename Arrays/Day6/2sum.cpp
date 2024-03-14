#include <bits/stdc++.h>
using namespace std;

// find two elements of the array whose sum happens to be a target.
string sum2(vector<int> &v, int target)
{
    map<int, int> mp;
    for (size_t i = 0; i < v.size(); i++)
    {
        int a = v[i];
        int more = target - a;
        if (mp.find(more) != mp.end())
        {
            return "yes"; // return "mp[more], i";
        }
        mp[a] = (int)i;
    }
    return "no"; // return "";
}

// optimal solution.
bool sum2O(vector<int> &v, int target)
{
    sort(v.begin(), v.end());
    int left = 0, right = v.size() - 1;
    while (left < right)
    {
        int sum = v[left] + v[right];
        if (sum == target)
            return true;
        else if (sum < target)
            left++;
        else
            right--;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        a.push_back(ele);
    }
    int target;
    cin >> target;
    cout << sum2O(a, target) << " ";
    return 0;
}