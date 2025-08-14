#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

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
