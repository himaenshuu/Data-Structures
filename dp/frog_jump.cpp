#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// Using tabulation
class Solution
{
public:
    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(heights[0] - heights[1]);

        for (int i = 2; i < n; i++)
        {
            int onestep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int twostep = dp[i - 2] + abs(heights[i] - heights[i - 2]);

            dp[i] = min(onestep, twostep);
        }
        return dp[n - 1];
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    cout << obj.frogJump(v) << endl;

    return 0;
}
