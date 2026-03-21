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
        long long c, k;
        cin >> n >> c >> k;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());

        for (int i = 0; i < n; ++i)
        {
            if (a[i] > c)
                break;

            long long maxFlipsOnThis = c - a[i];
            long long use = min(k, maxFlipsOnThis);

            c += a[i] + use;
            k -= use;
        }

        cout << c << '\n';
    }

    return 0;
}
