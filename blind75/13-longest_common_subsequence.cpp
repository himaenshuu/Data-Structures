/*
Problem: Longest Common Subsequence (LeetCode #1143)
Difficulty: Medium
Top Companies: Amazon, Google, Microsoft, Adobe, Uber
Entry-Level Importance (0-2 YoE): 3/5

Early Intuition:
Build a 2D DP table where dp[i][j] = LCS length of first i chars of text1
and first j chars of text2.
If characters match: dp[i][j] = dp[i-1][j-1] + 1.
If they don't: dp[i][j] = max(dp[i-1][j], dp[i][j-1]) (skip one character from either string).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

// Tabulation approach: tc= O(n^2)
class Solution
{
public:
    int LCS(vector<int> &v1, vector<int> &v2)
    {
        int n = v1.size(), m = v2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (v1[i - 1] == v2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }

        return dp[n][m];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1 = {1, 2, 3, 4, 5, 8};
    vector<int> v2 = {4, 5, 6, 7, 8};
    Solution sol;
    cout << sol.LCS(v1, v2) << endl;

    return 0;
}
