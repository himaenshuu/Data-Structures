#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        // Regions: L = p[0..x-1], M = p[x..y-1], R = p[y..n-1]
        // M can be cyclically rotated arbitrarily.
        // L and R keep their relative order, and only the split point in D=L+R can change.
        vector<int> D;
        D.reserve(x + (n - y));
        for (int i = 0; i < x; ++i) D.push_back(p[i]);
        for (int i = y; i < n; ++i) D.push_back(p[i]);

        int m = y - x;
        int start = x; // index of minimum element in M (global winner for lexicographic minimum)
        for (int i = x + 1; i < y; ++i) {
            if (p[i] < p[start]) start = i;
        }
        int v = p[start];

        // For fixed first M element v, best insertion is before first D[i] > v.
        int k = 0;
        while (k < (int)D.size() && D[k] < v) ++k;

        vector<int> ans;
        ans.reserve(n);

        for (int i = 0; i < k; ++i) ans.push_back(D[i]);
        for (int cnt = 0; cnt < m; ++cnt) {
            int idx = x + ((start - x + cnt) % m);
            ans.push_back(p[idx]);
        }
        for (int i = k; i < (int)D.size(); ++i) ans.push_back(D[i]);

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }

    return 0;
}
