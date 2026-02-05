/*
================================================================================
LeetCode #62 - Unique Paths (Dynamic Programming)
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Apple
- Adobe
- Bloomberg
- Goldman Sachs
- Uber

PROBLEM STATEMENT:
A robot is located at top-left corner of m x n grid. The robot can only move
down or right at any point. Find the number of unique paths to reach the
bottom-right corner.

CONSTRAINTS:
- 1 <= m, n <= 100

EXAMPLE 1:
Input: m = 3, n = 2
Output: 3
Explanation: From top-left to bottom-right, there are 3 unique paths

EXAMPLE 2:
Input: m = 3, n = 7
Output: 28

DYNAMIC PROGRAMMING APPROACH (Memoization):
- Base case: dp[0][0] = 1 (one way to stay at start)
- Out of bounds: return 0
- Recursive: dp[i][j] = dp[i-1][j] + dp[i][j-1]
  (paths from top + paths from left)

TIME COMPLEXITY: O(m * n)
SPACE COMPLEXITY: O(m * n) for dp array

ALTERNATIVE APPROACHES:
1. Tabulation: O(m*n) time, O(m*n) space
2. Space Optimized: O(m*n) time, O(n) space
3. Mathematical: O(m+n) time, O(1) space using combinations

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// memoization

class Solution
{
public:
    int countPaths(int i, int j, vector<vector<int>> &dp)
    {
        // base cases
        if (i == 0 && j == 0)
            return 1;

        // outbond cases
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = countPaths(i - 1, j, dp);
        int left = countPaths(i, j - 1, dp);

        // edge cases
        return dp[i][j] = up + left;
    }

    int gridUniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp);
    }
};

// t.c = O(m*n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;

    Solution obj;
    cout << obj.gridUniquePaths(m, n) << endl;

    return 0;
}
