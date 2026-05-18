/*
Problem: Coin Change (LeetCode #322)
Difficulty: Medium
Top Companies: Amazon, Google, Microsoft, Meta, Adobe
Entry-Level Importance (0-2 YoE): 5/5

Problem Statement:
Given an array of coin denominations and a total amount, return the minimum
number of coins needed to make up that amount. If it is impossible, return -1.
You have an unlimited supply of each coin.

Early Intuition:
This is the most commonly asked DP problem at entry level.
Build a dp array where dp[i] = fewest coins to make amount i.
For each amount, try every coin: if you can make (i - coin), then dp[i] = min(dp[i], dp[i-coin] + 1).
Start with dp[0] = 0 and initialize everything else to infinity.

Optimal Approach:
Bottom-up DP. dp[0]=0, dp[1..amount]=INT_MAX. For each amount i, try every
coin c where c<=i: dp[i] = min(dp[i], dp[i-c]+1). Return dp[amount] or -1.
Time: O(amount * coins), Space: O(amount).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
 
// for the same problem, if coins were not given, we can use the greedy approach
class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp) // recursion
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins)
        {
            int res = solve(coins, amount - coin, dp);

            if (res != INT_MAX)
            {
                ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }

    int coinChange2(vector<int> &coins, int amount) // iteration approach tc=O(nk)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int a = 1; a <= amount; a++)
        {
            for (int c : coins)
            {
                if (a - c >= 0)
                {
                    dp[a] = min(dp[a], dp[a - c] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;

        else
            return dp[amount];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}