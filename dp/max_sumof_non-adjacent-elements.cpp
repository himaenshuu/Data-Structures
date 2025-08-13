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
        if (n <= 0)
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

    int fun2(vector<int> &arr2)
    {
        int n = arr2.size();
        if (n < -0)
        {
            return arr[0];
        }

        vector<int> dp(n, -1);
        dp[0] = arr[0];
        dp[i] = max(arr[0], arr[i]);

        for (int i = 0; i < n; i++)
        {
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 2]; // return the second last element of dp array
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
    cout << obj.fun(v) << endl;
    return 0;
}
