#include <bits/stdc++.h>
using namespace std;

static const long long INF = (long long)4e18;

int crt42[7][6]; // smallest r in [0,41] with r%7=a and r%6=b

// Returns minimal m >= 0 such that for all x in v:
// min(v2(x+m), v3(x+m)) >= v7(x+m), or INF if impossible.
static long long solveM(const vector<long long> &v)
{
    if (v.empty())
        return 0;

    array<vector<long long>, 7> buckets;
    for (long long x : v)
        buckets[x % 7].push_back(x);

    long long best = INF;

    for (int a = 0; a < 7; a++)
    { // a = m % 7
        if (a >= best)
            break;

        int cls = (7 - a) % 7; // x % 7 == cls <=> x + m divisible by 7
        const vector<long long> &cur = buckets[cls];

        if (cur.empty())
        {
            // Nothing can be divisible by 7 for this residue class, so all are valid.
            best = min(best, (long long)a);
            if (best == 0)
                return 0;
            continue;
        }

        int mod6 = (int)(cur[0] % 6);
        bool ok = true;
        for (long long x : cur)
        {
            if ((int)(x % 6) != mod6)
            {
                ok = false;
                break;
            }
        }
        if (!ok)
            continue;

        int need6 = (6 - mod6) % 6; // need m % 6 so that x+m divisible by 6
        int r = crt42[a][need6];
        if (r >= best)
            continue;

        vector<long long> nxt;
        nxt.reserve(cur.size());
        for (long long x : cur)
        {
            // x+r is divisible by 42 here.
            nxt.push_back((x + r) / 42);
        }

        // Prevent infinite self-loop branch like [1,1,...] with r=41.
        if (nxt == cur)
            continue;

        long long sub = solveM(nxt);
        if (sub >= INF)
            continue;

        long long cand = r + 42LL * sub;
        if (cand < best)
        {
            best = cand;
            if (best == 0)
                return 0;
        }
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int a = 0; a < 7; a++)
    {
        for (int b = 0; b < 6; b++)
        {
            for (int r = 0; r < 42; r++)
            {
                if (r % 7 == a && r % 6 == b)
                {
                    crt42[a][b] = r;
                    break;
                }
            }
        }
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        // Necessary condition: all numbers must become divisible by 6 together.
        // So all ai must have same residue modulo 6.
        bool sameMod6 = true;
        int r = (int)(a[0] % 6);
        for (int i = 1; i < n; i++)
        {
            if ((int)(a[i] % 6) != r)
            {
                sameMod6 = false;
                break;
            }
        }

        if (!sameMod6)
        {
            cout << -1 << '\n';
            continue;
        }

        long long t0 = (6 - r) % 6; // smallest non-negative so ai+t0 is divisible by 6
        vector<long long> c(n);
        for (int i = 0; i < n; i++)
            c[i] = (a[i] + t0) / 6;

        long long m = solveM(c);
        if (m >= INF)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << (t0 + 6LL * m) << '\n';
        }
    }

    return 0;
}
