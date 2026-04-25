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

        vector<long long> ab(n + 1), sod(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> ab[i];
            sod[i] = sod[i - 1] + ab[i];
        }

        vector<int> id(n);
        iota(id.begin(), id.end(), 1);

        sort(id.begin(), id.end(), [&](int i, int j)
             {
            long long x = sod[i - 1], y = sod[j - 1];
            if (x != y) return x < y;
            return i < j; });

        vector<int> pk(n + 1);
        for (int i = 0; i < n; i++)
        {
            pk[id[i]] = n - i;
        }

        for (int i = 1; i <= n; i++)
        {
            cout << pk[i] << (i == n ? '\n' : ' ');
        }
    }

    return 0;
}
