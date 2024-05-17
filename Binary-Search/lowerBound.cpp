#include <bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target)
{
    int ans = arr.size();
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int upperBound(vector<int> &arr, int target)
{
    int ans = arr.size();
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= target)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans;
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
    int target;
    cin >> target;
    cout << lowerBound(arr, target);
    cout << upperBound(arr, target);
    return 0;
}