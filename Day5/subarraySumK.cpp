#include <bits/stdc++.h>
using namespace std;

int subarrayMaxLen(vector<int> &v, long long k)
{
    map<long long, int> mp;
    int sum = 0, maxLen = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum == k)
            maxLen = maxLen > (int)(i + 1) ? maxLen : i + 1;

        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxLen = maxLen > len ? maxLen : len;
        }

        // there comes a edge case where we have 2 0 0 3 the longest is 3 but ans is 1,
        // to overcome this we should check whether the map already contains the last sum if it isn't then you can insert.
        // this is nothing but finding the left most index so as to find the longest subarray.
        // this change makes it work for + and - numbers and for +ve you can optimse the code.
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxLen;
}

// optimsed code for posititve numberse subarray
int posSubarrayMaxLen(vector<int> &v, long long k)
{
    int right = 0, left = 0;
    long long sum = v[0];
    int n = v.size();
    int maxLen = 0;
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= v[left++];
        }
        if (sum == k)
        {
            int len = right - left + 1;
            maxLen = maxLen > len ? maxLen : len;
        }
        right++;
        if (right < n)
            sum += v[right];
    }
    return maxLen;
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
    cout << posSubarrayMaxLen(v, 3) << endl;
    return 0;
}