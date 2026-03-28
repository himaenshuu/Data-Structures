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

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
        }

        int ans;
        if (n == 1)
            ans = 1;
        else
            ans = 2;

        for (int i = 0; i < n; i++)
        {
            if (i)
                cout << ' ';
            cout << ans;
        }
        cout << '\n';
    }

    return 0;
}
