/*
================================================================================
Minimum Number of Coins (Greedy - Coin Change)
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Flipkart
- Paytm
- TCS
- Infosys

PROBLEM STATEMENT:
Find the minimum number of coins required to make a given value. You have an
infinite supply of coins of denominations: 1, 2, 5, 10, 20, 50, 100, 500, 1000.

CONSTRAINTS:
- 1 <= value <= 10^9
- Denominations: [1, 2, 5, 10, 20, 50, 100, 500, 1000]

EXAMPLE 1:
Input: value = 70
Output: 2
Explanation: 50 + 20 = 70 (2 coins)

EXAMPLE 2:
Input: value = 121
Output: 3
Explanation: 100 + 20 + 1 = 121 (3 coins)

GREEDY APPROACH:
1. Start with largest denomination
2. Use as many coins of that denomination as possible
3. Move to next smaller denomination
4. Repeat until value becomes 0

WHY GREEDY WORKS:
For canonical coin systems (like Indian currency), greedy gives optimal solution.

TIME COMPLEXITY: O(n) where n = number of denominations
SPACE COMPLEXITY: O(1)

NOTE: For arbitrary coin systems, use Dynamic Programming for optimal solution!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);

    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int val;
    int count = 0;
    cin >> val;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (val >= v[i])
        {
            val = val - v[i];
            count++;
        }
    }

    cout << count << endl;

    return 0;
}

// t.c = O(n)