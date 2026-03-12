/*
Problem: Best Time to Buy and Sell Stock (LeetCode #121)
Difficulty: Easy
Top Companies: Amazon, Apple, Meta, Microsoft, Goldman Sachs, Adobe
Entry-Level Importance (0-2 YoE): 5/5

Early Intuition:
Scan left to right while keeping track of the minimum price seen so far.
At each day, profit = current price - minimum so far.
Track the maximum across all such profits — no need to store the full array.
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
//Greedy approach works here 
//tc=O(n)


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {7, 2, 5, 9};
    Solution sol;
    cout << sol.maxProfit(vect);

    return 0;
}