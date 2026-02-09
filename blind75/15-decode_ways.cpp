#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();
        if (n == 0 || s[0] == '0')
            return 0;

        vector<int> dp(n + 1, 0); // initilize it with 0
        dp[0] = 1;                // ways to decode empty str is 1.
        dp[1] = 1;                // ways to decode single size str is 1.

        for (int i = 2; i <= n; i++)
        {
            // first verify valid one digit and two digit
            int onedigit = s[i - 1] - '0';
            int twodigit = stoi(s.substr(i - 2, 2)); // takes 2 size substr.

            if (onedigit != 0)
                dp[i] += dp[i - 1];
            if (twodigit >= 10 && twodigit <= 26)
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}