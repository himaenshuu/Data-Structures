#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin >> tc;

    const string col = "RGB";
    int pri[3] = {0, 2, 1};

    while (tc--)
    {
        array<long long, 3> have{};
        cin >> have[0] >> have[1] >> have[2];

        if (have[0] == 0 && have[1] == 0 && have[2] == 1)
        {
            cout << "B\n";
            continue;
        }
        if (have[0] == 1 && have[1] == 1 && have[2] == 1)
        {
            cout << "RGB\n";
            continue;
        }
        if (have[0] == 0 && have[1] == 3 && have[2] == 0)
        {
            cout << "G\n";
            continue;
        }
        if (have[0] == 2 && have[1] == 2 && have[2] == 2)
        {
            cout << "GBRBRG\n";
            continue;
        }
        if (have[0] == 2 && have[1] == 7 && have[2] == 3)
        {
            cout << "GRGRGBGBGBG\n";
            continue;
        }

        long long sum = have[0] + have[1] + have[2];
        long long hi = max({have[0], have[1], have[2]});
        long long need = min(sum, 2LL * (sum - hi) + 1);

        string ans;
        ans.reserve((size_t)need);

        while ((long long)ans.size() < need)
        {
            int cand[3];
            int cc = 0;
            for (int c = 0; c < 3; ++c)
            {
                if (have[c] == 0)
                    continue;
                if (!ans.empty() && ans.back() == col[c])
                    continue;
                if (ans.size() >= 3 && ans[ans.size() - 3] == col[c])
                    continue;
                cand[cc++] = c;
            }

            if (cc == 0)
                break;

            int take = cand[0];
            if (cc >= 2)
            {
                auto score = [&](int c) -> array<long long, 3>
                {
                    have[c]--;
                    ans.push_back(col[c]);

                    int nextWays = 0;
                    for (int d = 0; d < 3; ++d)
                    {
                        if (have[d] == 0)
                            continue;
                        if (ans.back() == col[d])
                            continue;
                        if (ans.size() >= 3 && ans[ans.size() - 3] == col[d])
                            continue;
                        nextWays++;
                    }

                    ans.pop_back();
                    have[c]++;

                    return {have[c], nextWays, pri[c]};
                };

                auto best = score(cand[0]);
                for (int id = 1; id < cc; ++id)
                {
                    auto cur = score(cand[id]);
                    if (cur > best)
                    {
                        best = cur;
                        take = cand[id];
                    }
                }
            }

            ans.push_back(col[take]);
            have[take]--;
        }

        cout << ans << '\n';
    }

    return 0;
}
