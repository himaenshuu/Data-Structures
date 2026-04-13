#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> l(n + 1, 0), r(n + 1, 0), parent(n + 1, -1);
        for (int i = 0; i < n; ++i) {
            cin >> l[i] >> r[i];
            if (l[i] != 0) parent[l[i]] = i;
            if (r[i] != 0) parent[r[i]] = i;
        }
        parent[0] = -1;

        vector<int> order;
        order.reserve(n + 1);
        vector<int> st;
        st.push_back(0);
        while (!st.empty()) {
            int v = st.back();
            st.pop_back();
            order.push_back(v);
            if (r[v] != 0) st.push_back(r[v]);
            if (l[v] != 0) st.push_back(l[v]);
        }

        vector<long long> sub(n + 1, 1), down(n + 1, 1), ans(n + 1, 0);
        for (int i = (int)order.size() - 1; i >= 0; --i) {
            int v = order[i];
            if (l[v] == 0 && r[v] == 0) {
                sub[v] = 1;
                down[v] = 1;
            } else {
                long long left_sub = (l[v] ? sub[l[v]] : 0);
                long long right_sub = (r[v] ? sub[r[v]] : 0);
                long long left_down = (l[v] ? down[l[v]] : 0);
                long long right_down = (r[v] ? down[r[v]] : 0);
                sub[v] = 1 + left_sub + right_sub;
                down[v] = 1 + left_down + 1 + right_down + 1;
            }
        }

        ans[0] = 0;
        for (int v : order) {
            if (l[v] != 0) ans[l[v]] = (ans[v] + down[l[v]]) % MOD;
            if (r[v] != 0) ans[r[v]] = (ans[v] + down[r[v]]) % MOD;
        }

        for (int k = 1; k <= n; ++k) {
            if (k > 1) cout << ' ';
            cout << ans[k];
        }
        cout << '\n';
    }

    return 0;
}

