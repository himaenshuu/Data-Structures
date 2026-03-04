#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

/*
LeetCode 57: Insert Interval

Problem Statement:
Given a list of non-overlapping intervals sorted by start time, and a new interval,
insert the new interval into the list so that:
1) The final list remains sorted by start time.
2) No intervals overlap (merge whenever required).

Input:
- intervals: vector of intervals where intervals[i] = [start_i, end_i]
- newInterval: [start, end]

Output:
- Updated list of merged, non-overlapping, sorted intervals.

Approach (Greedy + Linear Scan):
1) Add all intervals that end before newInterval starts (left part).
2) Merge all intervals that overlap with newInterval (middle part).
3) Add remaining intervals (right part).

Why this works:
- Because intervals are already sorted and non-overlapping, all possible overlaps with
    newInterval appear in one continuous block.

Complexity:
- Time: O(N)
- Space: O(N) for output vector

Difficulty:
- Medium

Commonly asked in:
- Google, Amazon, Microsoft, Meta (Facebook), Adobe

Example:
intervals = [[1,3],[6,9]], newInterval = [2,5]
Output = [[1,5],[6,9]]
*/

class Solution
{
public:
    // Divide it into three parts : left, mid and right
    vector<vector<int>> insert(vector<vector<int>> &intervals,
                               vector<int> &newInterval)
    {

        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        // Process the left side
        while (i < n && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // Process the overlapping case
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        res.push_back(newInterval); // it also deals with the empty intervals cases

        // Process the right side
        while (i < n)
        {
            res.push_back(intervals[i]);
            i++;
        }

        return res;
    }
};

// tc = O(N)
// sc = O(N)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> ans = sol.insert(intervals, newInterval);

    cout << "Merged intervals: [";
    for (int i = 0; i < (int)ans.size(); i++)
    {
        cout << "[" << ans[i][0] << "," << ans[i][1] << "]";
        if (i + 1 < (int)ans.size())
            cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}