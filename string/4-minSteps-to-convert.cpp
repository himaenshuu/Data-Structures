/*
================================================================================
Minimum deletions + insertions to transform String A into String B (LCS-based)
================================================================================

LEETCODE NOTE:
This exact "min deletions + insertions" framing is commonly taught via LCS.
Related LeetCode problems include:
- LeetCode #72 (Edit Distance) (allows replace too)
- LeetCode #583 (Delete Operation for Two Strings) (deletions only)

PROBLEM STATEMENT (paraphrased for this file):
Given two strings a and b, find the minimum number of deletions and insertions
needed to transform a into b when only deletion and insertion operations are
allowed.

DIFFICULTY: Medium

COMMONLY ASKED BY (varies by year/team):
- Amazon, Microsoft, Google

ENTRY-LEVEL IMPORTANCE:
- Medium (core LCS / string DP pattern)

OPTIMAL APPROACH:
Let L = LCS(a, b). Then:
- deletions = |a| - L
- insertions = |b| - L
Time: O(n*m), Space: O(n*m) (can be optimized to O(min(n,m))).

================================================================================
*/

#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

static int LCS_length(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}

pair<int, int> MinDelAndIns(const string &a, const string &b)
{
    int n = (int)a.size();
    int m = (int)b.size();
    int L = LCS_length(a, b);

    int del = n - L;
    int ins = m - L;

    return {del, ins};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // Single test case
    string a = "heap";
    string b = "pea";
    auto ans = MinDelAndIns(a, b);
    cout << "deletions=" << ans.first << " insertions=" << ans.second << endl;

    return 0;
}