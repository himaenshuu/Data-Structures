#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumArraySum(vector<int>& a) {
        int mx = 0, n = (int)a.size();
        for (int x : a) mx = max(mx, x);

        const int inf = 1e9;
        vector<char> has(mx + 1, 0);
        vector<int> mn(mx + 1, inf);
        for (int i = 0; i < n; ++i) has[a[i]] = 1;

        for (int d = 1; d <= mx; ++d) {
            if (!has[d]) continue;
            for (int m = d; m <= mx; m += d) mn[m] = min(mn[m], d);
        }

        long long s = 0;
        for (int i = n - 1; i >= 0; --i) s += mn[a[i]];
        return s;
    }
};
