#include <bits/stdc++.h>
using namespace std;

static bool cE(const vector<long long> &timers, long long cycleLen)
{
    bool pos = true;
    long long strk = 1;

    for (int idx = 1; idx < (int)timers.size(); ++idx)
    {
        if (timers[idx - 1] == timers[idx])
        {
            ++strk;
            if (strk >= cycleLen)
            {
                pos = false;
            }
        }
        else
        {
            strk = 1;
        }
    }

    return pos;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long m;
        int n;
        cin >> n >> m;

        vector<long long> a(n);
        for (int pos = 0; pos < n; pos++)
        {
            cin >> a[pos];
        }

        cout << (cE(a, m) ? "YES" : "NO") << '\n';
    }

    return 0;
}
