#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution
{
    ll rv(ll x)
    {
        ll y = 0;
        while (x)
        {
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }

public:
    long long primeSum(int n)
    {
        ll a = n, b = rv(n), l = min(a, b), r = max(a, b), s = 0;
        if (r < 2)
            return 0;
        if (l <= 2 && 2 <= r)
            s += 2;

        l = max(3LL, l);
        if ((l & 1) == 0)
            ++l;
        if (l > r)
            return s;

        static vector<int> p;
        static int dn = 1;
        int m = (int)sqrt((long double)r);
        if (m > dn)
        {
            vector<char> sv(m + 1, 1);
            sv[0] = 0;
            if (m >= 1)
                sv[1] = 0;
            for (int i = 2; i * 1LL * i <= m; ++i)
                if (sv[i])
                    for (int j = i * i; j <= m; j += i)
                        sv[j] = 0;
            p.clear();
            for (int i = 3; i <= m; i += 2)
                if (sv[i])
                    p.push_back(i);
            dn = m;
        }

        ll k = (r - l) / 2 + l;
        vector<char> ok(k, 1);
        for (int x : p)
        {
            if (1LL * x * x > r)
                break;
            ll st = max(1LL * x * x, ((l + x - 1) / x) * 1LL * x);
            if ((st & 1) == 0)
                st += x;
            for (ll v = st; v <= r; v += 2LL * x)
                ok[(v - l) / 2] = 0;
        }

        for (ll i = 0; i < k; ++i)
            if (ok[i])
                s += l + 2 * i;
        return s;
    }
};
