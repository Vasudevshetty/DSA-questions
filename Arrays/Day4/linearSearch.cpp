#include <bits/stdc++.h>
using namespace std;

int linearSearch(vector<int> array, int key)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        if (array[i] == key)
            return i;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> array;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        array.push_back(ele);
    }
    int key;
    cin >> key;
    cout << linearSearch(array, key);
    cout << endl;
    return 0;
}