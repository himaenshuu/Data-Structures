#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// memoization
class Solution
{
    const int INF = 1e9 / 2; // i have used this large value, so that it will be never chosen

public:
    int minSum(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &vect)
    {
        // base cases
        if (i == 0 && j == 0)
            return dp[i][j] = vect[i][j];

        // outbond cases
        if (j < 0 || j > i)
            return INF;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = minSum(i - 1, j, dp, vect);
        int diagonal = minSum(i - 1, j - 1, dp, vect);

        return dp[i][j] = vect[i][j] + min(up, diagonal);
    }

    int minSumPaths(vector<vector<int>> &vect)
    {
        int m = vect.size();
        if (m == 0)
            return 0;
        if (m == 1)
            return vect[0][0]; // only one element

        vector<vector<int>> dp(m, vector<int>(m, -1));

        int ans = INT_MAX / 2;
        for (int j = 0; j < m; j++)
        {
            ans = min(ans, minSum(m - 1, j, dp, vect));
        }
        return ans;
    }
};

// T.c = O(n^2)
// S.c = O(n^2)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m;
    cin >> m;

    vector<vector<int>> vect(m, vector<int>(m));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> vect[i][j];
        }
    }

    Solution obj;
    cout << obj.minSumPaths(vect) << endl;

    return 0;
}
