#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> overlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> v;

    for (size_t i = 0; i < arr.size(); i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (!v.empty() && end <= v.back()[1])
            continue;

        for (size_t j = i + 1; j < arr.size(); j++)
        {
            if (arr[j][0] <= end)
                end = max(end, arr[j][1]);
            else
                break;
        }
        v.push_back({start, end});
    }

    return v;
}

vector<vector<int>> overlappingIntervalsOptimal(vector<vector<int>> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (size_t i = 1; i < arr.size(); i++)
    {
        if(ans.empty() || ans.back()[1] < arr[i][0])
            ans.push_back(arr[i]);
        else
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }

    return ans;
}

int main()
{
    vector<vector<int>> v = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};
    for (vector<int> x : overlappingIntervalsOptimal(v))
    {
        cout << "(" << x[0] << ", " << x[1] << ")";
        cout << endl;
    }
    return 0;
}
