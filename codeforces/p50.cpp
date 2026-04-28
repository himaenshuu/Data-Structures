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

        int mx = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mx = max(mx, a[i]);
        }

        vector<int> b(mx + 1, 0);
        for (int x : a)
            b[x]++;

        vector<int> c(mx + 1), nxt(mx + 2);

        int l = 0, r = n;
        while (l < r)
        {
            int m = (l + r + 1) / 2;

            c = b;

            auto f = [&](int x)
            {
                while (x <= mx && nxt[x] != x)
                {
                    nxt[x] = nxt[nxt[x]];
                    x = nxt[x];
                }
                return (x <= mx ? x : mx + 1);
            };

            auto take = [&](int v)
            {
                c[v]--;
                if (c[v] == 0)
                    nxt[v] = f(v + 1);
            };

            nxt[mx + 1] = mx + 1;
            for (int i = mx; i >= 0; i--)
                nxt[i] = (c[i] ? i : nxt[i + 1]);

            bool ok = true;
            for (int x = m - 1; x >= 0; x--)
            {
                int need = 2 * x + 1;
                if (x <= mx && c[x] > 0)
                {
                    take(x);
                    continue;
                }

                if (need > mx)
                {
                    ok = false;
                    break;
                }

                int v = f(need);
                if (v > mx)
                {
                    ok = false;
                    break;
                }

                take(v);
            }

            if (ok)
            {
                l = m;
                continue;
            }
            r = m - 1;
        }

        cout << l << '\n';
    }

    return 0;
}
