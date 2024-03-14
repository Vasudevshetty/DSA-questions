#include<bits/stdc++.h>
using namespace std;

int profitOnSell(vector<int> &v){
    int item = v[0], profit = 0;
    for (size_t i = 1; i < v.size(); i++){
        int cost = v[i] - item;
        profit = max(profit, cost);
        item = min(item, v[i]);
    }
    return profit;
}

int main(){
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    cout << profitOnSell(v);
    return 0;
}