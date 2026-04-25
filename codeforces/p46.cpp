#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int nu;
    cin >> nu;

    vector<long long> alpha(nu);
    for (int i = 0; i < nu; i++)
    {
        cin >> alpha[i];
    }

    vector<long long> beta = alpha;
    nth_element(beta.begin(), beta.begin() + nu / 2, beta.end());
    long long mu = beta[nu / 2];

    vector<int> rho(nu + 1, 0), sigma(nu + 1, 0);
    for (int i = 1; i <= nu; i++)
    {
        rho[i] = rho[i - 1] + (alpha[i - 1] < mu);
        sigma[i] = sigma[i - 1] + (alpha[i - 1] > mu);
    }

    vector<int> xi(nu + 1), eta(nu + 1);
    for (int i = 0; i <= nu; i++)
    {
        xi[i] = 2 * rho[i] - i;
        eta[i] = 2 * sigma[i] - i;
    }

    const int kappa = -1000000000;
    vector<int> delta(nu + 1, kappa);
    vector<int> omega[2];

    delta[0] = 0;
    omega[0].push_back(0);

    for (int rhoi = 1; rhoi <= nu; rhoi++)
    {
        int zeta = (rhoi ^ 1) & 1;
        int theta = kappa;

        for (int pi : omega[zeta])
        {
            if (xi[pi] >= xi[rhoi] && eta[pi] >= eta[rhoi])
            {
                theta = max(theta, delta[pi] + 1);
            }
        }

        delta[rhoi] = theta;
        if (delta[rhoi] >= 0)
        {
            omega[rhoi & 1].push_back(rhoi);
        }
    }

    cout << delta[nu] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tau;
    cin >> tau;
    while (tau--)
    {
        solve();
    }

    return 0;
}
