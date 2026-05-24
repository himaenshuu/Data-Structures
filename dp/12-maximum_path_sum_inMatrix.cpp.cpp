/* Question
We are given an ‘N *M’ matrix.We need to find the maximum path sum from any cell of the first row to any cell of the last row.
At every cell we can move in three directions : to the bottom cell(↓),
to the bottom - right cell(↘), or to the bottom - left cell(↙).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// memoization
class Solution
{
    const int INF = INT_MIN / 4; // i have used this large value, so that it will be never chosen

public:
    int maxSum(int i, int j, int k, vector<vector<vector<int>>> &dp, vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();

        // base cases
        if (i == m - 1)
        {
            if (j == k)
                return vect[i][j];
            else
                return vect[i][j] + vect[i][k];
        }
        int var = vect[i][j] + (j != k ? vect[i][k] : 0);
        int value = 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        for (int p = -1; p <= 1; p++)
        {
            for (int q = -1; q <= 1; q++)
            {
                int nc1 = j + p;
                int nc2 = k + q;

                if (nc1 >= 0 && nc2 >= 0 && nc1 <= n - 1 && nc2 <= n - 1)
                {
                    value = max(value, maxSum(i + 1, nc1, nc2, dp, vect));
                }
            }
        }
        return dp[i][j][k] = var + value;
    }

    // memoization top-down approach
    int maxfallingPath1(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();
        if (m == 0)
            return 0;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        int ans;
        ans = maxSum(0, 0, n - 1, dp, vect);
        return ans;
    }

    // Iteration bottom-up approach
    int maxfallingPath2(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();
        if (m == 0)
            return 0;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                dp[m - 1][j][k] = vect[m - 1][j] + (j != k ? vect[m - 1][k] : 0);
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    dp[i][j][k] = vect[i][j] + (j != k ? vect[i][k] : 0);
                    int value = 0;

                    for (int p = -1; p <= 1; p++)
                    {
                        for (int q = -1; q <= 1; q++)
                        {
                            int nc1 = j + p;
                            int nc2 = k + q;

                            if (nc1 >= 0 && nc2 >= 0 && nc1 <= n - 1 && nc2 <= n - 1)
                            {
                                value = max(value, dp[i + 1][nc1][nc2]);
                            }
                        }
                    }
                    dp[i][j][k] += value;
                }
            }
        }

        return dp[0][0][n - 1];
    }

    int maxfallingPath3(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();
        if (m == 0)
            return 0;

        vector<vector<int>> next(n, vector<int>(n, -1)), curr(n, vector<int>(n, -1));

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                next[j][k] = vect[m - 1][j] + (j != k ? vect[m - 1][k] : 0);
            }
        }

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    curr[j][k] = vect[i][j] + (j != k ? vect[i][k] : 0);
                    int value = 0;

                    for (int p = -1; p <= 1; p++)
                    {
                        for (int q = -1; q <= 1; q++)
                        {
                            int nc1 = j + p;
                            int nc2 = k + q;

                            if (nc1 >= 0 && nc2 >= 0 && nc1 <= n - 1 && nc2 <= n - 1)
                            {
                                value = max(value, next[nc1][nc2]);
                            }
                        }
                    }
                    curr[j][k] += value;
                }
            }
            next = curr;
        }

        return next[0][n-1];
    }
};

// In both of the above approach, only differnce is the recursive call in memoization
// which causes overhead of function call stack and results in TLE

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin >> m >> n;

    vector<vector<int>> vect(m, vector<int>(n));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vect[i][j];
        }
    }

    Solution obj;
    cout << obj.maxfallingPath3(vect) << endl;

    return 0;
}
