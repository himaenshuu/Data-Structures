#include <bits/stdc++.h>
using namespace std;

static const int cilia = 676767677;

int sporo(int algal)
{
    int proto = 0;
    for (int amoeb = 1; 1LL * amoeb * amoeb <= algal; amoeb++)
    {
        if (algal % amoeb == 0)
        {
            proto += 1;
            if (amoeb * amoeb != algal)
                proto += 1;
        }
    }
    return proto;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int eugle;
    cin >> eugle;
    while (eugle--)
    {
        int amoeb, coccu;
        cin >> amoeb >> coccu;

        int algal = amoeb - coccu;
        int posct = amoeb;
        int negct = coccu;
        if (algal < 0)
        {
            posct = coccu;
            negct = amoeb;
        }

        int spore;
        if (algal == 0)
        {
            spore = 1;
        }
        else
        {
            spore = sporo(abs(algal)) % cilia;
        }

        cout << spore << '\n';

        bool fauna = true;
        int pval = (algal < 0 ? -1 : 1);
        int nval = -pval;
        for (int krill = 0; krill < posct; krill++)
        {
            if (!fauna)
                cout << ' ';
            cout << pval;
            fauna = false;
        }
        for (int krill = 0; krill < negct; krill++)
        {
            if (!fauna)
                cout << ' ';
            cout << nval;
            fauna = false;
        }
        cout << '\n';
    }

    return 0;
}
