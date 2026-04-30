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

        int ok = 0;
        for (char c : s)
        {
            ok += (c == '(');
        }

        cout << (2 * ok == n ? "YES\n" : "NO\n");
    }

    return 0;
}
