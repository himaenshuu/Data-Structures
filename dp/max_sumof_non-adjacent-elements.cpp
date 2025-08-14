#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
class Solution
{
public:
    int fun(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return arr[0];

        vector<int> dp(n, -1);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // dp[i] is storing the value of max sum possible upto i

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};


// space optimized O(1)
int maxNonAdjacentSum(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int prev2 = arr[0], prev1 = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

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
    cout << obj.fun(v) << endl;
    return 0;
}
