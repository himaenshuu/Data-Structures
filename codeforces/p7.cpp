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

        int lim = n * n;
        vector<int> freq(lim + 1, 0);

        int mx = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int x;
                cin >> x;
                int f = ++freq[x];
                if (f > mx)
                    mx = f;
            }
        }

        if (mx <= n * (n - 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}
