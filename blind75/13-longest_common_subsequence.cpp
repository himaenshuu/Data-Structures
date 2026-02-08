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
