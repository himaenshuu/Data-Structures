#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// frog_jump problem with k distances
class Solution
{
public:
    int fun(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i && j <= k; j++)
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
        return dp[n - 1];
    }
};

// TC = O(n*k) SC = O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;
    Solution obj;
    cout << obj.fun(v, k) << endl;

    return 0;
}
