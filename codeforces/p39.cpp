#include <bits/stdc++.h>
using namespace std;

static const int MOD = 676767677;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int ordo, meta;
        if (!(cin >> ordo >> meta))
            break;

        vector<int> numer(meta, 0);
        vector<int> hora(ordo);
        bool okin = (meta > 0);
        for (int iter = 0; iter < ordo; iter++)
            cin >> hora[iter];
        for (int vale : hora)
        {
            if (vale < 0 || vale >= meta)
                okin = false;
            else
                numer[vale]++;
        }

        if (!okin)
        {
            cout << 0 << '\n';
            continue;
        }

        long long suma = 1;
        vector<int> prior(meta + 1, 0);
        for (int temp = 1; temp <= meta; temp++)
            prior[temp] = prior[temp - 1] + numer[temp - 1];

        for (int iter = 0; iter < ordo; iter++)
        {
            int temp = hora[iter];
            int laev = (iter > 0 ? hora[iter - 1] : meta);
            int dext = (iter + 1 < ordo ? hora[iter + 1] : meta);
            int vici = min(laev, dext);

            long long viae = 1;
            if (temp > 0)
            {
                if (vici >= temp)
                    viae = 0;
                else if (vici == temp - 1)
                    viae = prior[temp];
                else
                    viae = numer[temp - 1];
            }

            suma = (suma * viae) % MOD;
            if (suma == 0)
                break;
        }

        cout << suma << '\n';
    }
 
    return 0;
}
