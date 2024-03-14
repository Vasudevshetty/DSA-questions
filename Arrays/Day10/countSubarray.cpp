#include <bits/stdc++.h>
using namespace std;

// this is better, if we want to make it brute add another innner looop to it aste.
// problem is to find the count the number of subarrays whose sume is exactly k.
int countSubarrayBrute(vector<int> &v, int k)
{
    int count = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        int sum = 0;
        for (size_t j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

// optimal
int countSubarraysum(vector<int> &v, int k)
{
    map<int, int> hm;
    hm[0] = 1;
    int count = 0;
    int presum = 0;
    for (int c : v)
    {
        presum += c;
        int remove = presum - k;
        count += hm[remove];
        hm[presum] += 1;
    }
    return count;
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
    int k;
    cin >> k;
    cout << countSubarraysum(v, k);
    return 0;
}