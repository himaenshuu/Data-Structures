#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        bool activ = false;
        long long x, genom, vibr, spira;
        cin >> spira >> vibr;

        genom = spira + 2 * vibr;
        x = 2 * genom + 1;

        long long best_m = -1, best_n = -1;
        long long best_max = LLONG_MAX;

        for (long long i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                vector<long long> divisors = {i, x / i};
                for (long long stru : divisors)
                {
                    if (stru < 3)
                        continue;

                    long long plasm = (stru - 1) / 2;
                    long long capsu = genom - plasm;

                    if (capsu <= 0)
                        continue;

                    if (capsu % stru != 0)
                        continue;

                    long long ribo = capsu / stru;
                    if (ribo > 0)
                    {
                        long long max_val = max(ribo, plasm);
                        if (max_val < best_max || (max_val == best_max && plasm < best_m))
                        {
                            best_max = max_val;
                            best_m = plasm;
                            best_n = ribo;
                            activ = true;
                        }
                    }
                }
            }
        }

        if (activ)
        {
            cout << best_m << " " << best_n << "\n";
        }
        else
        {
            cout << "-1\n";
        }
    }

    return 0;
}
