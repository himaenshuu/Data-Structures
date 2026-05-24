/*
================================================================================
LeetCode #1312 - Minimum Insertion Steps to Make a String Palindrome
================================================================================

PROBLEM STATEMENT (paraphrased):
Given a string s, return the minimum number of characters you need to insert
anywhere in s so that the result is a palindrome.

DIFFICULTY: Hard

COMMONLY ASKED BY (varies by year/team):
- Amazon, Google, Microsoft, Meta

ENTRY-LEVEL IMPORTANCE:
- Medium (DP is important; this specific variant is less common for entry-level)

OPTIMAL APPROACH USED HERE:
Minimum insertions = n - LPS(s). This code computes LPS via LCS(s, reverse(s)).
Time: O(n^2), Space: O(n^2).

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
    int LCS(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        for (int i = 0; i < n; i++)
        {
            dp[i][0] = 0;
        }

        for (int i = 0; i < m; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][m];
    }

    // below is new code other than lcs
    int minInsertions(string s)
    {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());

        // lenght of string - lcs(s)
        return n - LCS(s, t);
    }
};

// O(N^2)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    string s = "mbadm";
    cout << sol.minInsertions(s) << endl;

    return 0;
}