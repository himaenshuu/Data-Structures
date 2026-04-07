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
        int lava, kelp;
        cin >> lava >> kelp;

        vector<int> fucus(kelp);
        vector<int> algal(lava);
        for (int i = 0; i < lava; i++)
            cin >> algal[i];
        for (int i = 0; i < kelp; i++)
            cin >> fucus[i];

        int diat = algal[fucus[0] - 1];
        int bloom = 0;
        vector<int> eugle(lava + 2, 0);
        for (int i = 1; i <= lava; i++)
        {
            int green = (algal[i - 1] != diat);
            eugle[i] = bloom ^ green;
            bloom = green;
        }
        eugle[lava + 1] = bloom;

        int spiro = 0;
        vector<int> anaba(kelp + 1, 0);
        for (int i = 1; i <= lava + 1; i++)
        {
            while (spiro < kelp && fucus[spiro] < i)
                spiro++;
            if (eugle[i])
                anaba[spiro]++;
        }

        int maxa = 0;
        int suma = 0;
        for (int v : anaba)
        {
            suma += v;
            maxa = max(maxa, v);
        }

        int ans = suma / 2;
        if (maxa > ans)
            ans = maxa;
        cout << ans << '\n';
    }

    return 0;
}
