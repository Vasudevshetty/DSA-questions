#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &v, int x)
{
    for (auto ele : v)
        if (ele == x)
            return true;
    return false;
}

int longestSubsequence(vector<int>& v){
    int longest = 1;
    for (size_t i = 0;i < v.size(); i++){
        int cnt = 1;
        int ele = v[i];
        while(linearSearch(v, ele + 1)){
            cnt++;
            ele++;
        }
        longest = longest > cnt ? longest : cnt;
    }
    return longest;
}

// better solution 
int longestSubsequenceB(vector<int>&v){
    int longest = 1;
    int last_smaller = INT_MIN;
    int cnt = 1;
    sort(v.begin(), v.end());
    for (size_t i = 0; i < v.size(); i++)
    {
        if(v[i] - 1 == last_smaller){
            last_smaller = v[i];
            cnt++;
        }else if(v[i] != last_smaller){
            last_smaller = v[i];
            cnt = 1;
        }
        longest = longest > cnt ? longest : cnt;
    }
    return longest;
}

// optimal solution
int longestSubsequenceO(vector<int>& v){
    int longest = 1;
    unordered_set<int> st;
    for(auto ele: v)
        st.insert(ele);
    
    for(auto it: st){
        if(st.find(it - 1) == st.end()){
            // if it is the first element of the sequence.
            int x = it, cnt = 1;
            while(st.find(x+1) != st.end()){
                cnt++;
                x++;
            }
            longest = longest > cnt ? longest : cnt;
        }
    }
    return longest;
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
    cout << longestSubsequence(v) << " ";
    cout << longestSubsequenceB(v) << " ";
    cout << longestSubsequenceO(v) << " ";
    return 0;
}