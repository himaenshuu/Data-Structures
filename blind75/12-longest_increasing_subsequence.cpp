/*
Problem: Longest Increasing Subsequence (LeetCode #300)
Difficulty: Medium
Top Companies: Amazon, Google, Microsoft, Meta, Uber
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given an integer array nums, return the length of the longest strictly
increasing subsequence. Elements do not need to be contiguous.

Early Intuition:
For every element, ask: what is the longest increasing subsequence that ends here?
To answer, look back at all previous elements smaller than the current one and take
the max of their LIS lengths, then add 1. This is classic O(n^2) DP. A binary
search optimisation can bring it to O(n log n).

Optimal Approach:
O(n^2) DP: dp[i] = 1 + max(dp[j]) for all j < i where nums[j] < nums[i].
O(n log n) approach: maintain a tails array. For each element, binary search
for its position in tails and replace or extend. tails.size() = LIS length.
Time: O(n log n), Space: O(n).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    // tabulation O(n^2)
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        int answer = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    // dp[i] stores the LIS ending at the index i, not till the index i
                }
            }
            answer = max(answer, dp[i]);
        }

        return answer;
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> nums = {2, 4, 5, 1, 6};
    cout << sol.lengthOfLIS(nums);

    cout << "" << endl;

    return 0;
}