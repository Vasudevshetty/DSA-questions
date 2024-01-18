#include <bits/stdc++.h>
using namespace std;

// brute force
int onlyOnce(vector<int> &v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        int count = 0;
        int num = v[i];
        for (size_t j = 0; j < v.size(); j++)
        {
            if (v[j] == num)
                count++;
        }
        if (count == 1)
            return num;
    }
    return -1;
}

// better solution
int onlyOnceHash(vector<int> &v){
    unordered_map<int, int> mp;
    for(auto it : v)
        mp[it]++;
    for(auto it: mp){
        if(it.second == 1)
            return it.first;
    }
    return -1;
}

// optimal solution
int onlyOnceO(vector<int>& v){
    int Xor = 0;
    for(auto it: v){
        Xor ^= it;
    }
    return Xor;
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
    cout << onlyOnceO(v) << endl;
    return 0;
}