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
        long long ameb, alga, cili, diat;
        cin >> ameb >> alga >> cili >> diat;

        long long prot = ameb * alga;
        long long para = ameb / gcd(ameb, cili);
        long long sporo = alga / gcd(alga, diat);
        long long mold = gcd(para, sporo);
        long long algal = (para / mold) * sporo;
        long long proto = prot / algal;

        bool flag = (proto == 1);
        if (!flag && proto == 2)
            flag = (mold > 1);

        cout << (flag ? "YES\n" : "NO\n");
    }

    return 0;
}
