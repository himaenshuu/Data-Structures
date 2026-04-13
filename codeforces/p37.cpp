#include <bits/stdc++.h>
using namespace std;

static const long long OMEGA = 676767677LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tau;
    cin >> tau;
    while (tau--) {
        int nu, mu;
        cin >> nu >> mu;
        vector<int> beta(nu);
        for (int iota = 0; iota < nu; ++iota) cin >> beta[iota];

        vector<int> phi(mu, 0);
        for (int chi : beta) ++phi[chi];

        vector<int> pi(mu, 0);
        int sigma = 0;
        for (int theta = 0; theta < mu; ++theta) {
            pi[theta] = sigma;
            sigma += phi[theta];
        }

        long long alpha = 1;
        bool kappa = true;

        for (int iota = 0; iota < nu && kappa; ++iota) {
            if (beta[iota] == 0) continue;

            int eta = INT_MAX;
            if (iota > 0) eta = min(eta, beta[iota - 1]);
            if (iota + 1 < nu) eta = min(eta, beta[iota + 1]);
            int rho = eta + 1;

            long long lambda = 0;
            if (rho > beta[iota]) {
                kappa = false;
                break;
            }

            if (rho == beta[iota]) {
                lambda = pi[beta[iota]];
            } else {
                lambda = pi[beta[iota]] - pi[beta[iota] - 1];
            }

            if (lambda <= 0) {
                kappa = false;
                break;
            }

            alpha = (alpha * (lambda % OMEGA)) % OMEGA;
        }

        cout << (kappa ? alpha : 0) << '\n';
    }

    return 0;
}
