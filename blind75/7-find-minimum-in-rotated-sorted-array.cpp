/*
Problem: Find Minimum in Rotated Sorted Array (LeetCode #153)
Difficulty: Medium
Top Companies: Amazon, Microsoft, Google, Apple, Meta
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given a sorted array of unique integers that has been rotated between 1 and n
times, find and return the minimum element. Must run in O(log n).

Early Intuition:
The array has two sorted halves joined at a rotation point.
The minimum is always at the start of the right (unsorted) half.
Use binary search: if nums[mid] > nums[right], the minimum is in the right
half; otherwise it is in the left half (including mid).

Optimal Approach:
Binary search with left=0, right=n-1. While left < right:
  mid = (left+right)/2
  if nums[mid] > nums[right]: left = mid+1
  else: right = mid
Return nums[left]. Time: O(log n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {3, 4, 5, 1, 2};
    Solution sol;
    cout << sol.findMin(v) << endl;

    return 0;
}