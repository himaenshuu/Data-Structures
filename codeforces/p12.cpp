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
        string s;
        cin >> n >> s;

        vector<int> seen(n + 1, 0);
        int cur = 1;
        seen[cur] = 1;

        for (int step = 0; step < n; ++step)
        {
            if (s[cur - 1] == 'R')
                cur++;
            else
                cur--;
            seen[cur] = 1;
        }

        int ans = 0;
        for (int i = 1; i <= n; ++i)
            ans += seen[i];
        cout << ans << '\n';
    }

    return 0;
}
