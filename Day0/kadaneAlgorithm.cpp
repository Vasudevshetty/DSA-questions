/*Given an array Arr[] of N integers.
 Find the contiguous sub-array(containing at least one number) which has the maximum sum and return its sum*/

#include <bits/stdc++.h>
using namespace std;

int maxSubarraySum(int *arr, int n){
    int sum = 0, maxSum = arr[0];
    for(int i = 0; i < n; i++){
        if(sum < 0) sum = 0;
        sum+=arr[i];
        maxSum = max(maxSum, sum);
    }
    return maxSum;
}

int main(){
    int n = 5;
    int arr[] = {1,2,3,-2,5};
    cout << maxSubarraySum(arr, n);
    return 0;
}
