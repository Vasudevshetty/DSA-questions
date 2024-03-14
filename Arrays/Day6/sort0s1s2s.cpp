#include <bits/stdc++.h>
using namespace std;

// brute force is to sort using any algo , quick or merge.

// better appraoch is to
vector<int> sort012s(vector<int> &v)
{
    int cnt0, cnt1, cnt2;
    cnt0 = cnt1 = cnt2 = 0;
    for (auto it : v)
    {
        if (it == 0)
            cnt0++;
        else if (it == 1)
            cnt1++;
        else if (it == 2)
            cnt2++;
    }
    for (int i = 0; i < cnt0; i++)
        v[i] = 0;
    for (int i = cnt0; i < cnt1 + cnt0; i++)
        v[i] = 1;
    for(int i = cnt0 + cnt1; i < (int)v.size(); i++)
        v[i] = 2;
     return v;
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

// optimal soluiton using dutch national flag algorithm..
vector<int> sort012sO(vector<int> &v){
    int low = 0, mid = 0, high = v.size() - 1;
    while(mid <= high){
        if(v[mid] == 0){
            swap(v[low], v[mid]);
            mid++;
            low++;
        }else if(v[mid] == 1)
            mid++;
        else if(v[mid] == 2){
            swap(v[mid], v[high]);
            high--;
        }
    }
    return v;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n;i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    v = sort012sO(v);
    for(auto it: v)
        cout << it << " ";
    cout << endl;
    return 0;
}