/*
Problem: Search in Rotated Sorted Array (LeetCode #33)
Difficulty: Medium
Top Companies: Amazon, Meta, Microsoft, Google, Uber
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given a sorted array rotated at some pivot and an integer target, return the
index of target if found, or -1 if not. Must run in O(log n).

Early Intuition:
In a rotated sorted array, one of the two halves around mid is always fully sorted.
Identify the sorted half (compare nums[left] with nums[mid]), then check if the
target lies within that sorted range. If yes, search there; otherwise search the
other half. This keeps binary search's O(log n) bound.

Optimal Approach:
Binary search. At each step determine which half is sorted:
  If left half sorted (nums[left] <= nums[mid]) and target in [left..mid]: go left, else go right.
  If right half sorted and target in [mid+1..right]: go right, else go left.
Time: O(log n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target && nums[left] <= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        if (target == nums[left])
            return left;
        if (target == nums[right])
            return right;
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int t = 0;
    Solution sol;
    cout << sol.search(v, t) << endl;

    return 0;
}