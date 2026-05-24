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
    int maxSum(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &vect)
    {
        // outbond cases
        if (j < 0 || j >= vect[0].size())
            return INF;

        // base cases
        if (i == 0)
            return dp[i][j] = vect[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = maxSum(i - 1, j, dp, vect);
        int upleft = maxSum(i - 1, j - 1, dp, vect);
        int upright = maxSum(i - 1, j + 1, dp, vect);

        int best = max(up, max(upleft, upright));
        return dp[i][j] = vect[i][j] + best;
    }

    // memoization top-down approach
    int maxfallingPath1(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();
        if (m == 0)
            return 0;

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int ans = INT_MIN / 2;
        for (int j = 0; j < n; j++)
        {
            ans = max(ans, maxSum(m - 1, j, dp, vect));
        }
        return ans;
    }

    // Iteration bottom-up approach
    int maxfallingPath2(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base case: first row = same as vect
        for (int j = 0; j < n; j++)
            dp[0][j] = vect[0][j];

        // Build DP row by row
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int up = dp[i - 1][j];
                int upleft = (j > 0) ? dp[i - 1][j - 1] : INT_MIN / 2;
                int upright = (j < n - 1) ? dp[i - 1][j + 1] : INT_MIN / 2;

                dp[i][j] = vect[i][j] + max({up, upleft, upright});
            }
        }

        // Answer = max in last row
        return *max_element(dp[m - 1].begin(), dp[m - 1].end());
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
    cout << obj.maxfallingPath2(vect) << endl;

    return 0;
}
