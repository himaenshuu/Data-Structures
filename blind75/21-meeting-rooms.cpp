/*
Problem Statement:
Given an array of meeting time intervals where intervals[i] = {start, end},
determine if a person can attend all meetings.

Example:
Input:  [[0, 30], [5, 10], [15, 20]]
Output: false
Reason: [0, 30] overlaps with [5, 10] and [15, 20].

Difficulty Level: Easy (LeetCode 252 - Meeting Rooms)
Commonly Asked In: Amazon, Google, Meta, Microsoft, Uber

Approach (Greedy + Sorting):
1. Sort all intervals by start time.
2. Check each adjacent pair.
3. If next.start < current.end, overlap exists -> cannot attend all.
4. If no overlap is found, return true.

Time Complexity: O(n log n) due to sorting.
Space Complexity: O(1) extra (ignoring sorting internals).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool canAttendMeetings(vector<vector<int>> &intervals)
    {
        // Sort by end time.
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
             { return a[1] < b[1]; });

        int n = intervals.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (intervals[i + 1][0] < intervals[i][1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test Case 1: Overlapping meetings -> expected false
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    bool canAttend1 = sol.canAttendMeetings(intervals1);
    cout << "Test 1 (expected false): " << (canAttend1 ? "true" : "false") << endl;

    // Test Case 2: Non-overlapping meetings -> expected true
    vector<vector<int>> intervals2 = {{7, 10}, {12, 14}};
    bool canAttend2 = sol.canAttendMeetings(intervals2);
    cout << "Test 2 (expected true): " << (canAttend2 ? "true" : "false") << endl;

    return 0;
}