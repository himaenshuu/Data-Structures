#include <bits/stdc++.h>
using namespace std;

static inline long long lcm_cap(long long x, long long y, long long cap) {
    long long g = gcd(x, y);
    __int128 v = (__int128)(x / g) * y;
    if (v > cap) return cap + 1; // enough for floor(m / lcm) = 0
    return (long long)v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, m;
        cin >> a >> b >> c >> m;

        long long ab = lcm_cap(a, b, m);
        long long ac = lcm_cap(a, c, m);
        long long bc = lcm_cap(b, c, m);
        long long abc = lcm_cap(ab, c, m);

        long long A = m / a;
        long long B = m / b;
        long long C = m / c;
        long long AB = (ab > m ? 0 : m / ab);
        long long AC = (ac > m ? 0 : m / ac);
        long long BC = (bc > m ? 0 : m / bc);
        long long ABC = (abc > m ? 0 : m / abc);

        long long alice = 6 * A - 3 * AB - 3 * AC + 2 * ABC;
        long long bob = 6 * B - 3 * AB - 3 * BC + 2 * ABC;
        long long carol = 6 * C - 3 * AC - 3 * BC + 2 * ABC;

        cout << alice << ' ' << bob << ' ' << carol << '\n';
    }

    return 0;
}
