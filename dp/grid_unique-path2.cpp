#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// memoization

class Solution
{
public:
    int countPaths(int i, int j, vector<vector<int>> &dp, vector<vector<int>> &vect)
    {
        // base cases
        if (i == 0 && j == 0)
            return 1;

        // outbond cases
        if (i < 0 || j < 0 || vect[i][j] == -1)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int up = countPaths(i - 1, j, dp, vect);
        int left = countPaths(i, j - 1, dp, vect);

        return dp[i][j] = up + left;
    }

    int gridUniquePaths(vector<vector<int>> &vect)
    {
        int n = vect.size();
        int m = vect[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp, vect);
    }
};
// t.c = O(m*n)

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
    cout << obj.gridUniquePaths(vect) << endl;

    return 0;
}
