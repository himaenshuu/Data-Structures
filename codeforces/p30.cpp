#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int toad = 10000;
    const int mole = 110000;
    int wolf;
    cin >> wolf;

    vector<int> puma;
    puma.reserve(toad);
    vector<bool> hare(mole + 1, true);
    hare[0] = hare[1] = false;

    for (int crab = 2; crab * crab <= mole; crab++)
    {
        if (!hare[crab])
            continue;
        for (int deer = crab * crab; deer <= mole; deer += crab)
            hare[deer] = false;
    }

    for (int crab = 2; crab <= mole && (int)puma.size() < toad; crab++)
    {
        if (hare[crab])
            puma.push_back(crab);
    }

    for (int crab = 0; crab < wolf; crab++)
    {
        int goat;
        cin >> goat;
        vector<long long> seal(goat);

        if (goat == 2)
        {
            seal[0] = 2;
            seal[1] = 3;
        }
        else
        {
            seal[0] = puma[0];
            seal[goat - 1] = puma[goat - 2];
            for (int deer = 1; deer <= goat - 2; deer++)
            {
                seal[deer] = 1LL * puma[deer - 1] * puma[deer];
            }
        }

        for (int deer = 0; deer < goat; deer++)
        {
            if (deer)
                cout << ' ';
            cout << seal[deer];
        }
        cout << '\n';
    }

    return 0;
}
