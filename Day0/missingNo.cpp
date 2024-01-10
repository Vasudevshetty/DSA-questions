/*Given an array of size N-1 such that it only contains distinct integers in the range of 1 to N. Find the missing element.*/

#include<bits/stdc++.h>
using namespace std;

int missingNo(vector<int>& array, int n){
    int sumN= 0;
    for(int i = 1; i <= n; i++) sumN+= i;

    int sum = 0;
    for(int key : array){
        sum += key;
    }
    return sumN - sum;
}

int main(){
    vector<int> array = {1, 2, 3, 5};
    int missing = missingNo(array, 5);
    cout << missing;
    return 0;
}