/*
Problem: Longest Increasing Subsequence (LeetCode #300)
Difficulty: Medium
Top Companies: Amazon, Google, Microsoft, Meta, Uber
Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
For every element, ask: what is the longest increasing subsequence that ends here?
To answer, look back at all previous elements smaller than the current one and take
the max of their LIS lengths, then add 1. This is classic O(n^2) DP. A binary
search optimisation can bring it to O(n log n).
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

    // recurison approach : take or not take at any index
    // tc=O(2^n)
    int solve(int index, int prevIndex, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (index == nums.size())
            return 0;

        if (dp[index][prevIndex + 1] != -1)
        {
            return dp[index][prevIndex + 1];
        }

        // Option 1 - Not take
        int notTake = solve(index + 1, prevIndex, nums, dp);

        // option 2 - If take
        int take = 0;
        if (prevIndex == -1 || nums[index] > nums[prevIndex])
        {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][prevIndex + 1] = max(take, notTake);
    }

    int lengthOfLIS1(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int ans = solve(0, -1, nums, dp);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> nums = {2, 4, 5, 1, 6};
    cout << sol.lengthOfLIS1(nums);

    cout << "" << endl;

    return 0;
}