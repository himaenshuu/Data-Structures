#include <bits/stdc++.h>
using namespace std;

long long f(long long x) { return x * (x + 1) / 2; }

long long get(const array<int, 4> &p, const array<int, 4> &cnt, int a, int b, int c, int d){
    int ok[4] = {a, b, c, d};
    long long s = 0, cur = 0;
    for (int t : p)
    {
        if (ok[t])
            cur += cnt[t];
        else
            s += f(cur), cur = 0;
    }
    s += f(cur);
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
        int n;
        cin >> n;

        array<int, 4> cnt = {0, 0, 0, 0};
        array<vector<int>, 4> got;

        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            int id = 0;
            if (x % 3 == 0)
                id |= 2;
            if (x % 2 == 0)
                id |= 1;
            got[id].push_back(x);
            cnt[id]++;
        }

        array<int, 4> best = {0, 1, 2, 3};
        array<int, 4> p = {0, 1, 2, 3};
        long long ans = (1LL << 62);
        long long all = f(n);

        sort(p.begin(), p.end());
        do
        {
            long long s2 = get(p, cnt, 1, 0, 1, 0);
            long long s3 = get(p, cnt, 1, 1, 0, 0);
            long long s6 = get(p, cnt, 1, 0, 0, 0);
            long long cur = all - s2 - s3 + s6;

            if (cur < ans)
            {
                ans = cur;
                best = p;
            }
        } while (next_permutation(p.begin(), p.end()));

        bool sp = false;
        for (int id : best){
            for (int x : got[id])
            {
                if (sp)
                    cout << ' ';
                cout << x;
                sp = true;
            }
        }
        cout << '\n';
    }

    return 0;
}
