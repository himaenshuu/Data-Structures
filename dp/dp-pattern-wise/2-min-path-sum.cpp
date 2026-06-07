#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    // recursion
    int mPS(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
    {
        // edge case
        if (i < 0 || j < 0)
            return INT_MAX / 2;
        if (i == 0 && j == 0)
            return dp[i][j] = grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = min(mPS(grid, i - 1, j, dp), mPS(grid, i, j - 1, dp)) + grid[i][j];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return mPS(grid, m - 1, n - 1, dp);
    }

    // iteration
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX / 2));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1)
                    dp[i][j] = grid[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
            }
        }

        return dp[m][n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}