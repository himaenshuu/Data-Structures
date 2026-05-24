/*
================================================================================
LeetCode #516 - Longest Palindromic Subsequence
================================================================================

PROBLEM STATEMENT (paraphrased):
Given a string s, return the length of the longest subsequence of s that is a
palindrome (not necessarily contiguous).

DIFFICULTY: Medium

COMMONLY ASKED BY (varies by year/team):
- Amazon, Google, Microsoft, Meta, Bloomberg, Adobe

ENTRY-LEVEL IMPORTANCE:
- Medium-High (classic DP pattern)

OPTIMAL APPROACH USED HERE:
Compute LPS as LCS(s, reverse(s)) using dynamic programming.
Time: O(n^2), Space: O(n^2) (can be optimized to O(n) space).

================================================================================
*/

#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        // quick analogy, it is the lcs of the given string and its reverse
        int n = s.size();
        string a = s;
        reverse(a.begin(), a.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s[i - 1] == a[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    string s = "bbbab";
    cout << sol.longestPalindromeSubseq(s) << endl;

    return 0;
}