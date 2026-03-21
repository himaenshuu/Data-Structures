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
        vector<long long> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        vector<long long> vals = a;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = (int)vals.size();
        vector<int> bit(m + 1, 0);

        auto add = [&](int idx, int delta)
        {
            for (; idx <= m; idx += idx & -idx)
                bit[idx] += delta;
        };

        auto pref = [&](int idx)
        {
            int s = 0;
            for (; idx > 0; idx -= idx & -idx)
                s += bit[idx];
            return s;
        };

        vector<int> ans(n, 0);
        int suffixSize = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            int r = (int)(lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin()) + 1;
            int less = pref(r - 1);
            int greater = suffixSize - pref(r);
            ans[i] = max(less, greater);

            add(r, 1);
            suffixSize++;
        }

        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
