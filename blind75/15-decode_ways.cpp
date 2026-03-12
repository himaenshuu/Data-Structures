/*
Problem: Decode Ways (LeetCode #91)
Difficulty: Medium
Top Companies: Amazon, Meta, Microsoft, Google, Bloomberg
Entry-Level Importance (0-2 YoE): 3/5

Problem Statement:
A message containing letters A-Z can be encoded as numbers 1-26. Given a
non-empty string s of digits, return the number of ways to decode it.
Leading zeros (e.g. "06") are invalid; "0" alone is invalid.

Early Intuition:
Similar to climbing stairs but with validity checks. dp[i] = number of ways to
decode the substring s[0..i-1]. At each position, check if the single digit
s[i-1] is valid (1-9), and if the two-digit number s[i-2..i-1] is valid (10-26).
Add the corresponding previous dp values when valid.

Optimal Approach:
DP with two variables (prev2, prev1) instead of full array.
For each index i: ways = 0. If s[i-1] != '0': ways += prev1. If s[i-2..i-1] in [10..26]: ways += prev2.
Slide the window. Time: O(n), Space: O(1).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0); // initilize it with 0
        dp[0] = 1;                // ways to decode empty str is 1.
        dp[1] = 1;                // ways to decode single size str is 1.

        for (int i = 2; i <= n; i++)
        {
            // first verify valid one digit and two digit
            int onedigit = s[i - 1] - '0';
            int twodigit = stoi(s.substr(i - 2, 2)); // takes 2 size substr.

            if (onedigit != 0)
                dp[i] += dp[i - 1];
            if (twodigit >= 10 && twodigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}