/*Print a sequence of numbers starting with N, without using loop, where replace N with N - 5,
until N > 0. After that replace N with N + 5 until N regains its initial value.*/

#include <bits/stdc++.h>
using namespace std;

void patternHelper(int n, bool increasing, vector<int>& ans){
    ans.push_back(n);

    if(n > 0 && increasing) patternHelper(n-5, true, ans);
    else if (n != ans[0]) patternHelper(n+5, false, ans);
}

vector<int> pattern(int n){
    vector<int> ans;
    patternHelper(n, true, ans);
    return ans;
}

int main(){
    int n = 16;
    vector<int> ans = pattern(n);
    for(int key: ans) cout << key << " ";
    return 0;
}
