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

        bool ok = false;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (a == 100)
            {
                ok = true;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }

    return 0;
}
