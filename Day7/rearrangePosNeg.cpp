#include <bits/stdc++.h>
using namespace std;

// problem is to rearrange the given array of half positive and half negative elements to + - + - + -.. elements.

// brute force with time O(2*n) space O(n)
void rearrange(vector<int> &v)
{
    list<int> pos, neg;
    for (int i = 0; i < (int)v.size(); i++)
    {
        v[i] < 0 ? neg.push_back(v[i]) : pos.push_back(v[i]);
    }
    for (int i = 0; i < (int)v.size() / 2; i++)
    {
        v[2 * i] = pos.front();
        v[2 * i + 1] = neg.front();
        pos.pop_front();
        neg.pop_front();
    }
}

// optimal appraoch where i can reduce time to a single pass O(n)
vector<int> rearrangeO(vector<int>& v){
    vector<int> rv(v.size());
    int pos = 0, neg = 1;
    for (size_t i = 0; i < v.size(); i++){
        if(v[i] > 0){
            rv[pos] = v[i];
            pos += 2;
        }
        else
        {
            rv[neg] = v[i];
            neg += 2;
        }
    }
    return rv;
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
    rearrange(v);
    for(const auto& ele : v)
        cout << ele << " ";
    cout << endl;
    vector<int> rv = rearrangeO(v);
    for(const auto& ele : rv)
        cout << ele << " ";
    cout << endl;
    return 0;
}