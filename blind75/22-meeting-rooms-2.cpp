/*
Problem Statement:
Given an array of meeting time intervals where intervals[i] = {start, end},
return the minimum number of conference rooms required.

Example:
Input:  [[0, 30], [5, 10], [15, 20]]
Output: 2
Reason: One room for [0, 30], another for [5, 10] and [15, 20]

Difficulty Level: Medium (LeetCode 253 - Meeting Rooms II)
Commonly Asked In: Amazon, Google, Meta, Microsoft, Bloomberg, Uber

Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
Sort meetings by start time. Use a min-heap that holds the end times of all
ongoing meetings. For each new meeting, if the earliest-ending meeting is
already finished, reuse that room (pop the heap); otherwise open a new room.
The heap size at the end is the minimum number of rooms needed.
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    /*
    Approach (Min Heap / Priority Queue):
    1. Sort intervals by start time.
    2. Use min-heap to track end times of ongoing meetings.
    3. For each meeting:
       - If earliest ending meeting finishes before current starts, reuse that room (pop heap).
       - Add current meeting's end time to heap.
    4. Heap size = number of rooms needed.

    Time Complexity: O(n log n) = sorting + heap operations
    Space Complexity: O(n) = heap size
    */
    int minMeetingRooms(vector<vector<int>> &intervals)
    {

        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end()); // sorting by start time because we are comparing this to end time in priority queue

        priority_queue<int, vector<int>, greater<int>> pq; // put max at the top or max heap

        for (auto &i : intervals)
        {

            if (!pq.empty() && pq.top() <= i[0])
            {
                pq.pop();
            }

            pq.push(i[1]);
        }

        return pq.size();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test Case 1: Overlapping meetings -> expected 2 rooms
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    int rooms1 = sol.minMeetingRooms(intervals1);
    cout << "Test 1 (expected 2): " << rooms1 << endl;

    // Test Case 2: All overlapping -> expected 3 rooms
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    int rooms2 = sol.minMeetingRooms(intervals2);
    cout << "Test 2 (expected 1): " << rooms2 << endl;

    // Test Case 3: Multiple overlaps
    vector<vector<int>> intervals3 = {{1, 5}, {2, 3}, {4, 6}, {5, 7}};
    int rooms3 = sol.minMeetingRooms(intervals3);
    cout << "Test 3 (expected 2): " << rooms3 << endl;

    return 0;
}

/*This pattern appears everywhere:

1-meeting room scheduling
2-CPU job scheduling
3-cloud server allocation
4-airport runway management

When you see:

minimum resources
overlapping intervals
rooms / servers / machines

Your brain should trigger:

1 Sort by start
2 Track earliest finish
3 Min Heap
*/