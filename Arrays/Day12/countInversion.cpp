#include <bits/stdc++.h>
using namespace std;

int countInversions(vector<int> &arr)
{
    int count = 0;

    for (size_t i = 0; i < arr.size(); i++)
    {
        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int merge(vector<int> &v, int low, int mid, int high)
{
    int count = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (v[left] < v[right])
            temp.push_back(v[left++]);
        else
        {
            temp.push_back(v[right++]);
            count += (mid - left + 1);
        }
    }

    while (left <= mid)
        temp.push_back(v[left++]);

    while (right <= high)
        temp.push_back(v[right++]);

    for (int i = low; i <= high; i++)
        v[i] = temp[i - low];

    return count;
}

int mergeSort(vector<int> &v, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mergeSort(v, low, mid);
    count += mergeSort(v, mid + 1, high);
    count += merge(v, low, mid, high);
    return count;
}

int countInversionOptimal(vector<int> &v)
{
    return mergeSort(v, 0, v.size() - 1);
}

int main()
{
    vector<int> v = {5, 3, 2, 4, 1};
    cout << countInversions(v);
    cout << countInversionOptimal(v);
    cout << endl;
    for (int c : v)
        cout << c << " ";
    cout << endl;
    return 0;
}