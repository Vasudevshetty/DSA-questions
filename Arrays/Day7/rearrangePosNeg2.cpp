#include <bits/stdc++.h>
using namespace std;

// this is the 2nd variety of the rearrnge pos and neg elements of the given array.
// But here the no of pos and neg elements may not be same.
// if not same without distrubing the order add (append) at the end of the array.

// we have to fall back to brute force, that is collecting the neg and pos.
void rearrnge(vector<int>& v){
    vector<int> pos, neg;
    for(auto ele : v)
        ele > 0 ? pos.push_back(ele) : neg.push_back(ele);
    size_t i = 0, j = 0, k = 0;
    while(i < pos.size() && j < neg.size()){
        v[k++] = pos[i++];
        v[k++] = neg[j++];
    }
    while(i < pos.size())
        v[k++] = pos[i++];
    while(j < neg.size())
        v[k++] = neg[j++];
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
    rearrnge(v);
    for(auto ele : v)
        cout << ele << " ";
    cout << endl;
    return 0;
}