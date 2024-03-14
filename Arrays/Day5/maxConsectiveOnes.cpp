#include<bits/stdc++.h>
using namespace std;

int maxConsectiveOnes(vector<int>& a){
    int count = 0, max = -1;
    for(auto it: a){
        if(it == 0){
            if(max < count)
                max = count;
            count = 0;
        }
        else
            count++;
    }
    return max;
}

int main(){
    vector<int> a;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int ele;
        cin >> ele;
        a.push_back(ele);
    }
    cout << maxConsectiveOnes(a) << endl;
    return 0;
}