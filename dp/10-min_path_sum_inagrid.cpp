#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// memoization
class Solution
{
    const int INF = 1e9; // i have used this large value, so that it willbe never chosen

public:
    int minSum(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &vect)
    {
        // base cases
        if (i == 0 && j == 0)
            return dp[i][j] = vect[i][j];

        // outbond cases
        if (i < 0 || j < 0)
            return INF;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = minSum(i - 1, j, dp, vect);
        int left = minSum(i, j - 1, dp, vect);

        return dp[i][j] = vect[i][j] + min(up, left);
    }

    int minSumPaths(vector<vector<int>> &vect)
    {
        int m = vect.size();
        int n = vect[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return minSum(m - 1, n - 1, dp, vect);
    }
};

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
    cout << obj.minSumPaths(vect) << endl;

    return 0;
}
