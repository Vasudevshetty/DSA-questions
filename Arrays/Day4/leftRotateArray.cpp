#include<bits/stdc++.h>
using namespace std;

// the question is to rotate the array through left by 1 place.
void rotate(int* array, int n){
    int temp = *array;
    for (int i = 0; i < n - 1; i++){
        array[i] = array[i + 1];
    }
    array[n - 1] = temp;
}

// the question is to rotate the array through left by given k places.
void rotateK(int* array, int n, int k){
    k %= n;
    int temp[k];
    for (int i = 0; i < k; i++)
        temp[i] = array[i];
    for (int i = k; i < n; i++)
        array[i - k] = array[i];
    for (int i = 0; i < k; i++)
        array[n - k + i] = temp[i];
}

// the above answer is a better/brute approach since it takes extra space O(k). in order to optmise.
void reverse(int* array, int i, int j){
    while(i < j){
        int temp = array[i];
        array[i++] = array[j];
        array[j--] = temp;
    }
}

void rotateKO(int *array, int n, int k){
    k %= n;
    reverse(array, 0, k - 1);
    reverse(array, k, n - 1);
    reverse(array, 0, n - 1);
    // the time complexit yof this will be O(2*n); where n is the size of the array.
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    rotateKO(array, n,3);
    for(int a : array)
        cout << a << " ";
    cout << endl;
    return 0;
}