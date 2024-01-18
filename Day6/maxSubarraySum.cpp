#include <bits/stdc++.h>
using namespace std;

// max subarray sum of a given arrray

// brute force.
int maxSubarraySum(vector<int> &v)
{
    int maxS = INT_MIN;
    for (int i = 0; i < (int)v.size(); i++)
    {
        int sum = 0;
        for (int j = i; j < (int)v.size(); j++)
        {
            sum += v[j];
            maxS = maxS > sum ? maxS : sum;
        }
    }
    return maxS;
}

// kadane's algorithm.
int maxSubarraySumKadane(vector<int> &v)
{
    int maxS = INT_MIN;
    int sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        sum += v[i];
        if (sum > maxS)
            maxS = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxS;
}

// follow up question print those subarray sum.
string kadanePrint(vector<int> &v)
{
    string ans;
    int start = -1, end = -1;
    int maxS = INT_MIN, sum = 0;
    for (int i = 0; i < (int)v.size(); i++)
    {
        if (sum == 0)
            start = i;
        sum += v[i];
        if (sum > maxS)
        {
            maxS = sum;
            end = i;
        }
        if (sum < 0)
            sum = 0;
    }
    for (int i = start; i <= end; i++)
        ans += to_string(v[i]) + " ";
    ans += "max Sum is " +  to_string(maxS);
    return ans;
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
    cout << maxSubarraySumKadane(a) << endl;
    cout << kadanePrint(a) << endl;
    return 0;
}
