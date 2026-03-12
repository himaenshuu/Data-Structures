/*
Problem: Best Time to Buy and Sell Stock (LeetCode #121)
Difficulty: Easy
Top Companies: Amazon, Apple, Meta, Microsoft, Goldman Sachs, Adobe
Entry-Level Importance (0-2 YoE): 5/5

Problem Statement:
Given an array prices where prices[i] is the price of a stock on day i,
find the maximum profit you can achieve from one buy and one sell transaction.
You must buy before you sell. Return 0 if no profit is possible.

Early Intuition:
Scan left to right while keeping track of the minimum price seen so far.
At each day, profit = current price - minimum so far.
Track the maximum across all such profits — no need to store the full array.

Optimal Approach:
Two variables: minPrice and maxProfit. On each day update minPrice = min(minPrice,
prices[i]), then maxProfit = max(maxProfit, prices[i] - minPrice).
Time: O(n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            int pr = (prices[i] - prices[i - 1]);
            if (pr > 0)
            {
                max = max + pr;
            }
        }
        return max;
    }
};

// Greedy approach works here
// tc=O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {7, 2, 5, 9};
    Solution sol;
    cout << sol.maxProfit(vect);

    return 0;
}