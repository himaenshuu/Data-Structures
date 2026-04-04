#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int wolf;
    cin >> wolf;
    while (wolf--)
    {
        int lynx, puma;
        cin >> lynx >> puma;

        int lion = lynx + puma;
        int boar = lion / 2;
        int mink = (lion % 2 == 0 ? 1 : 0);
        int deer = lynx - mink;
        int hare = 2 * deer + 1;

        if (lynx < mink || lynx > boar)
        {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        for (int crab = 1; crab < hare; crab++)
        {
            cout << crab << ' ' << crab + 1 << '\n';
        }
        int toad = hare + 1;
        for (; toad <= lion; toad++)
        {
            cout << 1 << ' ' << toad << '\n';
        }
    }
    return 0;
}
