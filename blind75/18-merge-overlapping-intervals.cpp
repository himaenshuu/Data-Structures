#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

/*
LeetCode 56: Merge Intervals

Problem Statement:
Given an array of intervals where intervals[i] = [start_i, end_i], merge all overlapping
intervals and return a list of non-overlapping intervals that cover all intervals in the input.

Input:
- intervals: vector of intervals [start, end]

Output:
- vector of merged, non-overlapping intervals

Approach (Sorting + Greedy Merge):
1) Sort intervals by start time.
2) Traverse each interval:
     - If no overlap with the last interval in result, push it.
     - Otherwise merge by extending the end to max(current end, last end).

Why this works:
- After sorting, all potential overlaps for an interval appear next to it, so a single linear
    pass is enough to merge correctly.

Complexity:
- Time: O(N log N) due to sorting
- Space: O(N) for output

Difficulty:
- Medium

Commonly asked in:
- Amazon, Google, Microsoft, Meta (Facebook), Adobe

Example:
Input:  [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        // logic is push an element and check its back whether it overlaps with
        // other incoming element
        for (int i = 0; i < n; i++)
        {
            if (ans.empty() || intervals[i][0] > ans.back()[1])
            {
                ans.push_back(intervals[i]);
            }
            else
            {
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
            }
        }

        return ans;
    }
};
// tc = O(Nlogn)
// sc = O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = sol.merge(intervals);

    cout << "Merged intervals: [";
    for (int i = 0; i < (int)merged.size(); i++)
    {
        cout << "[" << merged[i][0] << "," << merged[i][1] << "]";
        if (i + 1 < (int)merged.size())
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
