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
        int lion;
        cin >> lion;

        vector<unsigned int> lynx(lion);
        for (int boar = 0; boar < lion; boar++)
            cin >> lynx[boar];

        int moos = lion * 31 + 5;
        vector<array<int, 2>> puma(moos, array<int, 2>{-1, -1});
        int deer = 1;

        auto otter = [&](unsigned int crab)
        {
            int ibis = 0;
            unsigned int hare = 0;
            for (int goat = 30; goat >= 0; goat--)
            {
                int crow = (crab >> goat) & 1U;
                int swan = crow ^ 1;
                int mink = puma[ibis][swan];
                if (mink != -1)
                {
                    hare |= (1U << goat);
                    ibis = mink;
                }
                else
                {
                    ibis = puma[ibis][crow];
                }
            }
            return hare;
        };

        auto snail = [&](unsigned int crab)
        {
            int ibis = 0;
            for (int goat = 30; goat >= 0; goat--)
            {
                int crow = (crab >> goat) & 1U;
                int &mink = puma[ibis][crow];
                if (mink == -1)
                    mink = deer++;
                ibis = mink;
            }
        };

        unsigned int hare = 0;
        for (int boar = 0; boar < lion; boar++)
        {
            if (boar == 0)
            {
                snail(lynx[boar]);
                continue;
            }
            hare = max(hare, otter(lynx[boar]));
            snail(lynx[boar]);
        }

        cout << hare << '\n';
    }

    return 0;
}
