#include <bits/stdc++.h>
using namespace std;

long long best(vector<long long> &v, int c)
{
    if (c == 0 || v.empty())
    {
        return 0;
    }

    int k = min(c, (int)v.size());
    partial_sort(v.begin(), v.begin() + k, v.end(), greater<long long>());

    long long cur = 0;
    long long mx = v[0];
    for (int i = 0; i < k; i++)
    {
        cur += v[i];
        mx = max(mx, cur);
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;

        vector<long long> o, e;
        o.reserve((n + 1) / 2);
        e.reserve(n / 2);

        long long s = 0;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            cin >> x;
            s += x;
            if (i & 1)
            {
                o.push_back(x);
            }
            else
            {
                e.push_back(x);
            }
        }

        int co = 0, ce = 0;
        for (int i = 0; i < m; i++)
        {
            int x;
            cin >> x;
            if (x & 1)
            {
                co++;
            }
            else
            {
                ce++;
            }
        }

        long long take = best(o, co) + best(e, ce);
        cout << s - take << '\n';
    }

    return 0;
}
