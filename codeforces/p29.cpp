#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int deer;
    cin >> deer;
    while (deer--)
    {
        int bear;
        cin >> bear;

        bool swan = true;
        for (int lynx = 0; lynx < bear; lynx++)
        {
            int hare = bear + 2 * lynx + 2;
            int crab = lynx + 1;
            int mole = hare - 1;

            if (!swan)
                cout << ' ';
            cout << crab << ' ' << mole << ' ' << hare;
            swan = false;
        }
        cout << '\n';
    }

    return 0;
}
