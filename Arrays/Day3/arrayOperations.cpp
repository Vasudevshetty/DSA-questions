/*Easy level array problems.*/
#include<bits/stdc++.h>
using namespace std;

// most optimial way of finding the largest in an array.
int maxArray(int *array, int n){
    int max = *(array);
    for (int i = 1; i < n; i++) if(max < *(array + i))
            max = *(array + i);
    return max;
}

// better way to find second largest element of the array.
int secondLargest(int *array, int n){
    int largest = maxArray(array, n);
    int secLarge = *array;
    for (int i = 1; i < n; i++)
        if(*(array+i) > secLarge && *(array+i) != largest)
            secLarge = *(array + i);
    return secLarge;
}

// optimial approach for finding a second largest element of the array is 
int secLargest(int *array, int n){
    int largest = *array, secLarge = INT_MIN;
    for (int i = 1; i < n; i++){
        if(*(array+i) > largest){
            secLarge = largest;
            largest = *(array + i);
        }
    }
    return secLarge;
}

bool isSorted(int *array, int n){
    for (int i = 0; i < n - 1; i++){
        if(*(array+i) > *(array+i+1))
            return false;
    }
    return true;
}

bool isSorted(int *array, int n, bool descending){
    if(descending){
        for(int i = 0; i < n; i++){
            if(*(array+i) < *(array+i+1))
                return false;
        }
        return true;
    }else
        return isSorted(array, n);
}

// function to find the unique elemetns of the array and keep it in the first few indecies..
int duplicatesBrute(int* array, int n){
    set<int> st;
    for(int i = 0; i < n; i++){
        st.insert(array[i]);
    }
    int idx = 0;
    for(auto it : st){
        array[idx++] = it;
    }
    // returns the no of unique elements
    return idx;
    // the time is o(n + nlogn) space if O(n)
}

// optimal appraoch for finding the duplicates is
int duplicatesOptimal(int *array, int n){
    int i = 0;
    for(int j = 1; j < n; j++){
        if(array[j] != array[i]){
            array[i + 1] = array[j];
            i++;
        }
    }
    return i;
}

int main(){
    int array[] = {1, 1, 1, 2, 2, 2};
    cout << maxArray(array, 6);
    cout << endl
         << secondLargest(array, 6) << endl
         << secLargest(array, 6) << endl;
    cout << isSorted(array, 6) << endl
                              << isSorted(array, 6, true) << endl;
    cout << duplicatesBrute(array, 6) << endl
         << duplicatesOptimal(array, 6) << endl;
    return 0;
}