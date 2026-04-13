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

        vector<int> a(n);
        bool worked = true;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b = a;
        sort(b.begin(), b.end());

        for (int i = 1; i < n; i++)
        {
            if (b[i] == b[i - 1])
            {
                worked = false;
                break;
            }
        }

        if (!worked)
        {
            cout << -1 << '\n';
            continue;
        }

        sort(a.begin(), a.end(), greater<int>());
        if (n > 0)
        {
            cout << a[0];
            for (int i = 1; i < n; i++)
            {
                cout << ' ' << a[i];
            }
        }
        cout << '\n';
    }

    return 0;
}
