#include <bits/stdc++.h>
using namespace std;

// lets find the union of two sorted arrays.
vector<int> unionOfArrays(vector<int> v1, vector<int> v2)
{
    vector<int> un;
    set<int> st;
    for (size_t i = 0; i < v1.size(); i++)
        st.insert(v1[i]);
    for (size_t i = 0; i < v2.size(); i++)
        st.insert(v2[i]);
    for (auto it : st)
        un.push_back(it);
    return un;
}

// optimal approach for the same question si 
vector<int> unionOfArrayO(vector<int> v1, vector<int> v2){
    vector<int> un;
    size_t i = 0, j = 0;
    while(i < v1.size() && j < v2.size()){
        if(v1[i] <= v2[j]){
            if(un.size() == 0 || un.back() != v1[i])
                un.push_back(v1[i]);
            i++;
        }else{
            if(un.size()==0||un.back()!=v2[i])
                un.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()){
        if(un.back()!=v1[i] || un.size()==0)
            un.push_back(v1[i++]);
    }
    while(j < v2.size()){
        if(un.back()!=v2[j] || un.size()==0)
            un.push_back(v2[i++]);
    }
    return un;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;
    vector<int> v1, v2;
    for (int i = 0; i < n1; i++)
    {
        int ele;
        cin >> ele;
        v1.push_back(ele);
    }
    for (int i = 0; i < n2; i++)
    {
        int ele;
        cin >> ele;
        v2.push_back(ele);
    }
    vector<int> u = unionOfArrays(v1, v2);
    for(auto it : u)
        cout << it << " ";
    cout << endl;
    return 0;
}