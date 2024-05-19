#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int x)
{
    int low = 0, high = arr.size() - 1;
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }

    return ans < (int)arr.size() ? arr[ans] : -1;
}

int ciel(vector<int> &arr, int x)
{
    int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
    return lb < (int)arr.size() ? arr[lb] : -1;
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
    cout << floor(arr, x) << " " << ciel(arr, x) << endl;
    return 0;
}