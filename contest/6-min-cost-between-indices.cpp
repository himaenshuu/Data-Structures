#include <bits/stdc++.h>
using namespace std;

class Solution {
    int cl(vector<int>& a, int i, int n) {
        if (i == 0) return 1;
        if (i == n - 1) return n - 2;
        long long x = 1LL * a[i] - a[i - 1];
        long long y = 1LL * a[i + 1] - a[i];
        return (x <= y ? i - 1 : i + 1);
    }

public:
    vector<long long> minCost(vector<int>& a, vector<vector<int>>& q) {
        int n = (int)a.size();
        vector<long long> pb(n), pf(n);

        for (int i = 0; i + 1 < n; ++i) {
            long long c = (cl(a, i, n) == i + 1 ? 1 : 1LL * a[i + 1] - a[i]);
            pf[i + 1] = pf[i] + c;
        }
        for (int i = n - 1; i > 0; --i) {
            long long c = (cl(a, i, n) == i - 1 ? 1 : 1LL * a[i] - a[i - 1]);
            pb[i - 1] = pb[i] + c;
        }

        vector<long long> ans;
        ans.reserve(q.size());
        for (auto& v : q) {
            int l = v[0], r = v[1];
            if (l <= r) ans.push_back(pf[r] - pf[l]);
            else ans.push_back(pb[r] - pb[l]);
        }
        return ans;
    }
};
