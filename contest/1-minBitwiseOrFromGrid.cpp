#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int minimumBitwiseOR(vector<vector<int>> &grid)
    {
        int ans = (1 << 20) - 1;
        for (int bit = 19; bit >= 0; --bit)
        {
            int wans = ans ^ (1 << bit);
            bool pos = true;
            for (auto &row : grid)
            {
                bool ok = false;
                for (auto x : row)
                {
                    if ((wans | x) == wans)
                    {
                        ok = true;
                        break;
                    }
                }
                if (!ok)
                {
                    pos = false;
                    break;
                }
            }
            if (!pos)
                continue;
            ans = wans;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v = {{2, 4}, {5, 8}, {2, 6}};
    Solution sol;
    int ans = sol.minimumBitwiseOR(v);
    cout << "ans is: " << ans << "\n";

    return 0;
}
