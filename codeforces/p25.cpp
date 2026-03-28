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
        int nu, kapa;
        cin >> nu >> kapa;

        vector<int> alpha(nu), beta(nu);
        for (int iota = 0; iota < nu; iota++)
            cin >> alpha[iota];
        for (int iota = 0; iota < nu; iota++)
            cin >> beta[iota];

        bool sigma = true;
        int lambda = nu - kapa;
        int rho = kapa - 1;

        vector<int> mu(nu + 1, 0);
        for (int iota = lambda; iota <= rho; iota++)
            mu[alpha[iota]] = 1;

        if (sigma)
        {
            vector<int> tau(nu + 1, 0);
            for (int iota = lambda; iota <= rho; iota++)
            {
                if (beta[iota] == -1)
                    continue;
                if (!mu[beta[iota]] || tau[beta[iota]])
                {
                    sigma = false;
                    break;
                }
                tau[beta[iota]] = 1;
            }
        }

        if (sigma)
        {
            for (int iota = 0; iota < nu; iota++)
            {
                if (iota >= lambda && iota <= rho)
                    continue;
                if (beta[iota] != -1 && beta[iota] != alpha[iota])
                {
                    sigma = false;
                    break;
                }
            }
        }

        cout << (sigma ? "YES\n" : "NO\n");
    }

    return 0;
}
