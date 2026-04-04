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
        long long sum = 0;
        int mx = INT_MIN;

        for (int i = 0; i < 7; i++)
        {
            int x;
            cin >> x;
            sum += x;
            mx = max(mx, x);
        }

        cout << (-sum + 2LL * mx) << '\n';
    }

    return 0;
}
