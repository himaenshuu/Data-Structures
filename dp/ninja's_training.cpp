// Ninja's Training

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int fun(int day, int last, vector<vector<int>> &points, vector<vector<int>> dp)
    {

        if (day == 0)
        {
            int maxi = 0;

            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                int point = points[day][task] + fun(day - 1, task, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }
    int ninjaTraining(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return fun(n - 1, 3, points, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> pts(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> pts[i][0] >> pts[i][1] >> pts[i][2];

    Solution obj;
    cout << obj.ninjaTraining(pts) << endl;

    return 0;
}

