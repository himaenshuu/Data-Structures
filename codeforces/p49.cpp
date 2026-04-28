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
        int n;
        cin >> n;

        vector<int> pqr(n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
            cin >> pqr[i];
        for (int i = 0; i + 1 < n; i++)
        {
            int a = pqr[i], b = pqr[i + 1];
            if (abs(a - b) == gcd(a, b))
                ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}
