#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &v, int key)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // int mid = (low + high) / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int binarySearchR(vector<int> &v, int key, int low, int high)
{
    if (low <= high)
    {
        // int mid = (low + high) / 2;
        int mid = low + (high - low) / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] > key)
            return binarySearchR(v, key, low, mid - 1);
        else
            return binarySearchR(v, key, mid + 1, high);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }
    int key;
    cin >> key;

    cout << binarySearch(v, key) << endl;
    cout << binarySearchR(v, key, 0, v.size() - 1) << endl;
    return 0;
}