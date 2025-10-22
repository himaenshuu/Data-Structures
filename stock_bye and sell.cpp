
/*
================================================================================
LeetCode #122 - Best Time to Buy and Sell Stock II
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Bloomberg
- Adobe
- Apple
- Goldman Sachs
- Uber
- Citadel

PROBLEM STATEMENT:
You are given an array prices where prices[i] is the price of a given stock
on the i-th day.

You want to maximize your profit by choosing multiple days to buy and sell
stocks. You can hold the stock for multiple days and make as many transactions
as you want.

Return the maximum profit you can achieve from these transactions. If you
cannot achieve any profit, return 0.

CONSTRAINTS:
- You must buy before you sell.
- You can make multiple transactions (buy/sell multiple times).
- You cannot hold multiple stocks at the same time.
- 1 <= prices.length <= 3 * 10^4
- 0 <= prices[i] <= 10^4

EXAMPLE 1:
Input: prices = [7, 1, 5, 3, 6, 4]
Output: 7
Explanation: Buy on day 2 (price = 1), sell on day 3 (price = 5) → profit = 4
            Buy on day 4 (price = 3), sell on day 5 (price = 6) → profit = 3
            Total profit = 4 + 3 = 7

EXAMPLE 2:
Input: prices = [1, 2, 3, 4, 5]
Output: 4
Explanation: Buy on day 1 (price = 1), sell on day 5 (price = 5) → profit = 4
            OR Buy and sell on each consecutive increase

EXAMPLE 3:
Input: prices = [7, 6, 4, 3, 1]
Output: 0
Explanation: Prices keep falling, no profit possible

APPROACH: Greedy Method
- Capture every positive price difference
- If prices[i] > prices[i-1], add the profit
- This works because any larger profit can be broken into smaller gains
- Time Complexity: O(n)
- Space Complexity: O(1)

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int findmaxprofit(vector<int> &prices)
{
    int size = prices.size();

    int sum = 0;
    int max_profit = 0;

    for (int i = 1; i < size; i++)
    {
        sum += prices[i] - prices[i - 1];
        if (sum < 0)
        {
            sum = 0;
        }
        max_profit = (sum > max_profit) ? sum : max_profit;
    }

    return max_profit;
}
// t.c=O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> vect(n);

    for (int i = 0; i < n; i++)
    {
        cin >> vect[i];
    }
    cout << findmaxprofit(vect);

    return 0;
}
