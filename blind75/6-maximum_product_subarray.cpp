/*
Problem: Maximum Product Subarray (LeetCode #152)
Difficulty: Medium
Top Companies: Amazon, Microsoft, Google, Meta, Adobe
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given an integer array nums, find a contiguous subarray that has the largest
product and return that product.

Early Intuition:
Unlike sum, a large negative product can become the maximum if multiplied by
another negative. Track both the maximum and minimum product ending at each
index. When you encounter a negative number, swap max and min before updating,
because multiplying a negative flips which is larger.

Optimal Approach:
Maintain curMax and curMin (product ending here). At each element:
  curMax = max(nums[i], nums[i]*curMax, nums[i]*curMin)
  curMin = min(nums[i], nums[i]*curMax_old, nums[i]*curMin_old)
Update global max. Time: O(n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// Logic: track both minprod and maxproduct
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxprod = nums[0];
        int minprod = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                swap(maxprod, minprod);
            }
            minprod = min(nums[i], minprod * nums[i]); // extend it or stop
            maxprod = max(nums[i], maxprod * nums[i]);
            ans = max(ans, maxprod);
        }
        return ans;
    }
};
// tc = O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> v = {3, -1, 4};
    cout << sol.maxProduct(v);

    return 0;
}