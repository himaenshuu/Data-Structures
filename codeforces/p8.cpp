#include <bits/stdc++.h>
using namespace std;

static long long sumLargestByFreq(const vector<int> &freq, int take)
{
    if (take <= 0)
        return 0;
    long long s = 0;
    int need = take;
    for (int val = (int)freq.size() - 1; val >= 1 && need > 0; --val)
    {
        if (freq[val] == 0)
            continue;
        int use = min(need, freq[val]);
        s += 1LL * use * val;
        need -= use;
    }
    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        long long win = a[p];

        long long initCost = 0;
        if (p > k)
        {
            vector<int> freqPref(m + 1, 0);
            long long prefSum = 0;
            for (int i = 1; i <= p - 1; i++)
            {
                freqPref[a[i]]++;
                prefSum += a[i];
            }
            long long keep = sumLargestByFreq(freqPref, k - 1);
            initCost = prefSum - keep;
        }

        vector<int> freqNonWin(m + 1, 0);
        long long nonWinSum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == p)
                continue;
            freqNonWin[a[i]]++;
            nonWinSum += a[i];
        }
        long long keepCycle = sumLargestByFreq(freqNonWin, k - 1);
        long long cycleCost = nonWinSum - keepCycle; // minimum cost of (n-k) mandatory non-win plays

        long long ans = 0;
        if (m >= initCost + win)
        {
            long long num = (long long)m - initCost + cycleCost;
            long long den = win + cycleCost;
            ans = num / den;
            if (ans < 1)
                ans = 1;
        }

        cout << ans << '\n';
    }

    return 0;
}
