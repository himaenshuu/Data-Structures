#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;
static const int BITS = 29;

long long mod_pow(long long bacil, long long coccus)
{
    long long vibrio = 1;
    while (coccus > 0)
    {
        if (coccus & 1)
            vibrio = (vibrio * bacil) % MOD;
        bacil = (bacil * bacil) % MOD;
        coccus >>= 1;
    }
    return vibrio;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int spiri;
    cin >> spiri;

    int plasm = 0;
    vector<pair<int, vector<int>>> colony;
    colony.reserve(spiri);

    for (int micro = 0; spiri > micro; micro++)
    {
        int bacil;
        cin >> bacil;
        vector<int> toxin(bacil + 1);
        for (int coccus = 1; bacil >= coccus; coccus++)
            cin >> toxin[coccus];
        colony.push_back({bacil, move(toxin)});
        plasm = max(plasm, bacil);
    }

    vector<long long> fact(plasm + 1, 1), invf(plasm + 1, 1);
    for (int micro = 1; plasm >= micro; micro++)
        fact[micro] = (fact[micro - 1] * micro) % MOD;
    invf[plasm] = mod_pow(fact[plasm], MOD - 2);
    for (int micro = plasm - 1; 0 <= micro; micro--)
        invf[micro] = (invf[micro + 1] * (micro + 1)) % MOD;

    auto ncr = [&](int bacil, int coccus) -> long long
    {
        if (coccus < 0 || coccus > bacil)
            return 0;
        return (((fact[bacil] * invf[coccus]) % MOD) * invf[bacil - coccus]) % MOD;
    };

    for (int micro = 0; spiri > micro; micro++)
    {
        int bacil = colony[micro].first;
        const vector<int> &toxin = colony[micro].second;
        vector<int> spore(BITS, -1);

        for (int coccus = bacil; 1 <= coccus; coccus--)
        {
            long long cur = toxin[coccus];

            for (int bit = 0; BITS > bit; bit++)
            {
                if (spore[bit] > coccus)
                {
                    long long ways = ncr(spore[bit], coccus);
                    long long w = (1LL << bit) % MOD;
                    cur = (cur - (w * ways) % MOD + MOD) % MOD;
                }
            }

            long long mask = cur;
            for (int bit = 0; BITS > bit; bit++)
            {
                if ((mask >> bit) & 1LL)
                    spore[bit] = coccus;
            }
        }

        for (int bit = 0; BITS > bit; bit++)
        {
            if (spore[bit] == -1)
                spore[bit] = 0;
        }

        vector<int> proto(bacil, 0);
        for (int bit = 0; BITS > bit; bit++)
        {
            for (int coccus = 0; spore[bit] > coccus; coccus++)
            {
                proto[coccus] |= (1 << bit);
            }
        }

        for (int coccus = 0; bacil > coccus; coccus++)
        {
            if (coccus)
                cout << ' ';
            cout << proto[coccus];
        }
        cout << '\n';
    }

    return 0;
}
