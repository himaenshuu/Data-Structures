#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

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
            cin >> a[i];

        long long s = 0;
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 1)
            {
                s += a[i];
                last = i;
            }
        }

        long long ans;
        if (last == -1)
        {
            ans = 1;
        }
        else
        {
            bool one = false;
            for (int i = last + 1; i < n; i++)
            {
                if (a[i] == 1)
                {
                    one = true;
                    break;
                }
            }
            ans = s + (one ? 1 : 0);
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}
