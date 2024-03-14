#include<bits/stdc++.h>
using namespace std;

// function to move all zeros to end of the array.
void moveZeros(int* array, int n){
    int zero = 0;
    for (int i = 0; i < n; i++){
        if(array[i] == 0){
            zero = i;
            break;
        }
    }
    for (int i = zero + 1; i < n; i++){
        if(array[i] != 0){
            int temp = array[i];
            array[i] = array[zero];
            array[zero] = temp;
            zero++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    moveZeros(array, n);
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;
    return 0;
}