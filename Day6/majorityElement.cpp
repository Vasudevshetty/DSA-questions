#include<bits/stdc++.h>
using namespace std;

// majority element mean that the number apears atleast n/2 times in the array.

// brute force for solving this question./
int majority(vector<int> &v){
    for(auto it: v){
        int cnt = 0;
        for(auto it2: v){
            if(it2 == it)
                cnt++;
        }
        if(cnt > (int)v.size()/2)
            return it;
    }
    return -1;
}

// better solution
int majorityMap(vector<int> &v){
    map<int, int> mp;
    for(auto it: v)
        mp[it]++;
    for(auto it: mp) if(it.second > (int)v.size()/2)
            return it.first;
    return -1;
}

// moore's algo... most optimal
int majorityO(vector<int> &v){
    int el, cnt = 0;
    for(int i = 0; i < (int)v.size(); i++){
        if(cnt == 0){
            cnt = 1;
            el = v[i];
        }else if(v[i] == el)
            cnt++;
        else
            cnt--;
        cout << cnt << " ";
    }
    cnt = 0;
    for(auto it : v) if (it == el)
            cnt++;
    cout << endl;
    return cnt >= (int)v.size() / 2 ? el : -1;
}


int main(){
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout << majorityO(v) << endl;
    return 0;
}