#include <bits/stdc++.h>
using namespace std;

// find the firs tand last occurence of a element in a array.

// bruet force
pair<int, int> findFirstLast(vector<int> &arr, int x)
{
    pair<int, int> p(-1, -1);
    for (int i = 0; i < (int)arr.size(); i++)
    {
        if (arr[i] == x)
        {
            if (p.first == -1)
                p.first = i;
            p.second = i;
        }
    }
    return p;
}

// using lowerboudn and upperbound of the array.
pair<int, int> findFirstLastLU(vector<int> &arr, int x)
{
    int first = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    int last = upper_bound(arr.begin(), arr.end(), x) - arr.begin() - 1;
    if (arr[first] == x && arr[last] == x)
        return {first, last};
    else
        return {-1, -1};
}

// using binarysearch
pair<int, int> findFirstLastBS(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int first = -1, last = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }

    if (first == -1)
        return {-1, -1};

    low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] > x)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return {first, last};
}

// find the count of occurences of a element in a sorted array.
int count(vector<int> &arr, int x)
{
    pair<int, int> fli = findFirstLastBS(arr, x);
    return fli.first == -1 || fli.second == -1 ? 0 : fli.second - fli.first + 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        arr.push_back(ele);
    }
    int x;
    cin >> x;
    cout << findFirstLast(arr, x).first << " " << findFirstLast(arr, x).second << endl;
    cout << findFirstLastLU(arr, x).first << " " << findFirstLastLU(arr, x).second << endl;
    cout << findFirstLastBS(arr, x).first << " " << findFirstLastBS(arr, x).second << endl;
    cout << count(arr, x) << endl;
    return 0;
}