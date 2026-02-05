#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// for the same problem, if coins were not given,we can use the greedy approach
class Solution
{
public:
    int solve(vector<int> &coins, int amount, vector<int> &dp) // recursion
    {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins)
        {
            int res = solve(coins, amount - coin, dp);

            if (res != INT_MAX)
            {
                ans = min(ans, 1 + res);
            }
        }

        return dp[amount] = ans;
    }
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }

    int coinChange2(vector<int> &coins, int amount) // iteration approach tc=O(nk)
    {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int a = 1; a <= amount, a++)
        {
            for (int c : coins)
            {
                if (a - c >= 0)
                {
                    dp[a] = min(dp[a], dp[a - c] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)
            return -1;

        else
            return dp[amount];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}