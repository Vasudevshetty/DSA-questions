#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int>& v){
    vector<int> ans;
    for (size_t i = 0; i < v.size(); i++){
        bool leader = true;
        for (size_t j = i + 1; j < v.size(); j++){
            if(v[i] < v[j]){
                leader = false;
                break;
            }
        }
        if(leader)
            ans.push_back(v[i]);
    }
    return ans;
}

// optmised approach.
vector<int> leadersO(vector<int>& v){
    vector<int> ans;
    int maxE = INT_MIN;
    for (int i = v.size() - 1; i >= 0; i--) 
    {
        if(v[i] > maxE){
            maxE = v[i];
            ans.push_back(maxE);
        }
    }
    // reverse(ans.begin(), ans.end()); if wanted in the same order teh array is given.
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    vector<int> ans = leadersO(v);
    for(auto ele : ans)
        cout << ele << " ";
    cout << endl;
    return 0;
}