#include <bits/stdc++.h>
using namespace std;

// functions to find missing no in a range of 1 to n natural numbers.
// brute force
int missing(vector<int>& arr, int n)
{
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (auto it : arr)
        {
            if (it == i)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            return i;
    }
    return 0;
}

// better approach space O(n) time O(2n)
int missingHash(vector<int>& a, int n)
{
    vector<bool> hash(n + 1, false);
    for (auto it : a)
        hash[it] = true;
    for (int i = 1; i <= n; i++)
        if (!hash[i])
            return i;
    return 0;
}

// optimal solutin
int missingOSum(vector<int>& a, int n){
    int sum = (n * (n + 1)) / 2;
    int aSum = 0;
    for(auto it : a)
        aSum += it;
    return sum - aSum;
}

// still better solution
int missingOXor(vector<int>& a, int n){
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n - 1; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int missingOXor2(vector<int>& a, int n){
    int xor1 = 0, xor2 = 0;
    for (int i = 1; i <= n; i++){
        xor1 ^= i;
    }
    for(auto it: a)
        xor2 ^= it;
    return xor1 ^ xor2;
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
    cout << missingOXor2(a, n + 1);
    return 0;
}