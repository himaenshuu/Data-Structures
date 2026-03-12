/*
Problem: Maximum Subarray / Kadane's Algorithm (LeetCode #53)
Difficulty: Medium
Top Companies: Amazon, Microsoft, Google, Adobe, Meta
Entry-Level Importance (0-2 YoE): 5/5

Problem Statement:
Given an integer array nums, find the contiguous subarray (containing at least
one number) which has the largest sum and return its sum.

Early Intuition:
Keep a running sum as you scan the array.
Whenever the running sum drops below zero, reset it to the current element
(a negative prefix can only drag down any future sum).
Track the maximum running sum seen at any point.

Optimal Approach:
Kadane's algorithm: curSum = max(nums[i], curSum + nums[i]); maxSum = max(maxSum, curSum).
Single pass, no extra space. Time: O(n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maximum = INT_MIN;
        int size = nums.size();
        int sum = 0;
        for (int i = 0; i < size; i++)
        {
            sum = max(nums[i], nums[i] + sum);
            maximum = max(maximum, sum);
        }
        return maximum;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution sol;
    cout << sol.maxSubArray(vect);

    return 0;
}