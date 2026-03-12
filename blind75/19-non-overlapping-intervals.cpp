/*
Problem: Non-overlapping Intervals (LeetCode #435)
Difficulty: Medium
Top Companies: Amazon, Google, Microsoft
Entry-Level Importance (0-2 YoE): 3/5

Early Intuition:
Greedy: sort intervals by end time. Always keep the interval with the earliest
end because it leaves maximum room for future intervals. If the next interval
starts before the current one ends, it overlaps — discard it (count as removed).
This minimises removals.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        // we have sorted by end time because we want minimum removal and it comes when we put the interval that ends later in the last to make free intervals for early ending intervals.
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &a, vector<int> &b)
             { return a[1] < b[1]; });

        int count = 0;
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (intervals[index][1] > intervals[i][0])
            {
                count++;
            }
            else
                index = i;
        }
        return (count);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}