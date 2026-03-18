#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();

        // d1: top-left -> bottom-right diagonal prefix
        // d2: top-right -> bottom-left diagonal prefix
        vector<vector<long long>> d1(m + 1, vector<long long>(n + 1, 0));
        vector<vector<long long>> d2(m + 1, vector<long long>(n + 2, 0));

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                d1[i + 1][j + 1] = d1[i][j] + grid[i][j];
                d2[i + 1][j + 1] = d2[i][j + 2] + grid[i][j];
            }
        }

        auto sumD1 = [&](int r1, int c1, int r2, int c2) -> long long
        {
            return d1[r2 + 1][c2 + 1] - d1[r1][c1];
        };

        auto sumD2 = [&](int r1, int c1, int r2, int c2) -> long long
        {
            return d2[r2 + 1][c2 + 1] - d2[r1][c1 + 2];
        };

        long long a = LLONG_MIN, b = LLONG_MIN, c = LLONG_MIN;
        auto push = [&](long long x)
        {
            if (x == a || x == b || x == c)
                return;
            if (x > a)
            {
                c = b;
                b = a;
                a = x;
            }
            else if (x > b)
            {
                c = b;
                b = x;
            }
            else if (x > c)
            {
                c = x;
            }
        };

        for (int r = 0; r < m; ++r)
        {
            for (int c = 0; c < n; ++c)
            {
                push(grid[r][c]);

                int maxK = min({r, c, m - 1 - r, n - 1 - c});
                for (int k = 1; k <= maxK; ++k)
                {
                    int tr = r - k, tc = c;
                    int rr = r, rc = c + k;
                    int br = r + k, bc = c;
                    int lr = r, lc = c - k;
                    
                    long long sum = 0;
                    sum += sumD1(tr, tc, rr, rc);
                    sum += sumD2(rr, rc, br, bc);
                    sum += sumD1(lr, lc, br, bc);
                    sum += sumD2(tr, tc, lr, lc);

                    sum -= grid[tr][tc] + grid[rr][rc] + grid[br][bc] + grid[lr][lc];
                    push(sum);
                }
            }
        }

        vector<int> ans;
        if (a != LLONG_MIN)
            ans.push_back((int)a);
        if (b != LLONG_MIN)
            ans.push_back((int)b);
        if (c != LLONG_MIN)
            ans.push_back((int)c);
        return ans;
    }
};
