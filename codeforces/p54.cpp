#include <bits/stdc++.h>
using namespace std;

struct Q { int l, r; long long o; };
struct N { int len, lk; };

inline long long K(int u, int c) { return (1LL * u << 21) ^ c; }

long long H(int x, int y, int p = 21, int rot = 0) {
    if (!p) return 0;
    int h = 1 << (p - 1);
    int s = (x < h) ? ((y < h) ? 0 : 3) : ((y < h) ? 1 : 2);
    s = (s + rot) & 3;
    static int dr[4] = {3, 0, 0, 1};
    int nx = x & (x ^ h), ny = y & (y ^ h);
    int nr = (rot + dr[s]) & 3;
    long long sub = 1LL << (2 * p - 2), base = s * sub;
    long long add = H(nx, ny, p - 1, nr);
    return base + ((s == 1 || s == 2) ? add : (sub - add - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m = 2 * n;
        vector<int> a(m);
        for (int i = 0; i < m; i++) cin >> a[i];

        vector<N> tr; tr.reserve(m + 3);
        tr.push_back({-1, 0}); tr.push_back({0, 0});
        unordered_map<long long, int> go; go.reserve(2 * (m + 5));

        vector<Q> q; q.reserve(m);
        int last = 1;

        for (int i = 0; i < m; i++) {
            int c = a[i], p = last;
            while (1) {
                int j = i - 1 - tr[p].len;
                if (j >= 0 && a[j] == c) break;
                p = tr[p].lk;
            }
            auto it = go.find(K(p, c));
            if (it != go.end()) { last = it->second; continue; }

            int id = (int)tr.size();
            tr.push_back({tr[p].len + 2, 0});
            go[K(p, c)] = id;

            if (tr[id].len == 1) tr[id].lk = 1;
            else {
                int u = tr[p].lk;
                while (1) {
                    int j = i - 1 - tr[u].len;
                    if (j >= 0 && a[j] == c) break;
                    u = tr[u].lk;
                }
                tr[id].lk = go[K(u, c)];
            }

            q.push_back({i - tr[id].len + 1, i, 0});
            last = id;
        }

        if (q.empty()) { cout << 0 << '\n'; continue; }

        for (auto &e : q) e.o = H(e.l, e.r);
        sort(q.begin(), q.end(), [](const Q &x, const Q &y) { return x.o < y.o; });

        int V = n + 1, B = max(1, (int)sqrt(V + 1)), nb = (V + B) / B;
        vector<int> f(V + 1, 0), z(nb, 0);
        for (int x = 0; x <= V; x++) z[x / B]++;

        auto add = [&](int x) {
            if (x > V) return;
            int b = x / B;
            if (!f[x]) z[b]--;
            f[x]++;
        };
        auto del = [&](int x) {
            if (x > V) return;
            int b = x / B;
            f[x]--;
            if (!f[x]) z[b]++;
        };

        int L = 0, R = -1, ans = 0;
        for (auto &e : q) {
            while (R < e.r) add(a[++R]);
            while (R > e.r) del(a[R--]);
            while (L < e.l) del(a[L++]);
            while (L > e.l) add(a[--L]);

            int b = 0;
            while (b < nb && !z[b]) b++;
            int s = b * B, t = min(V, s + B - 1), cur = V;
            for (int x = s; x <= t; x++) if (!f[x]) { cur = x; break; }
            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }
    return 0;
}
