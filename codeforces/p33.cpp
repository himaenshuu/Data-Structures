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
        int n, k;
        cin >> n >> k;
        bool worked = true;
        bool any = ((1LL * n * k) & 1LL);

        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            sum += x;
        }

        if (any)
            worked = (sum & 1LL);

        cout << (worked ? "YES\n" : "NO\n");
    }
    return 0;
}
