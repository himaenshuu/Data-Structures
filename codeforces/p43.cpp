#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int maxSum = 100 * n;
        vector<char> dp(maxSum + 1, 0), ndp(maxSum + 1, 0);
        dp[0] = 1;

        int builtMax = 0;

        for (int i = 0; i < n; i++)
        {
            int step = 100 / a[i];

            fill(ndp.begin(), ndp.end(), 0);

            for (int s = 0; s <= builtMax; s++)
            {
                if (!dp[s])
                    continue;

                for (int add = 0; add <= 100; add += step)
                {
                    ndp[s + add] = 1;
                }
            }

            builtMax += 100;
            dp.swap(ndp);
        }

        bool ok = true;
        for (int k = 0; k <= maxSum; k++)
        {
            if (!dp[k])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
