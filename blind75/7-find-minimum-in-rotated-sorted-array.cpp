/*
Problem: Find Minimum in Rotated Sorted Array (LeetCode #153)
Difficulty: Medium
Top Companies: Amazon, Microsoft, Google, Apple, Meta
Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
The array has two sorted halves joined at a rotation point.
The minimum is always at the start of the right (unsorted) half.
Use binary search: if nums[mid] > nums[right], the minimum is in the right
half; otherwise it is in the left half (including mid).
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