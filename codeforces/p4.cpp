#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXA = 1000000;
    vector<int> spf(MAXA + 1);
    for (int i = 0; i <= MAXA; i++) spf[i] = i;
    for (int i = 2; i * i <= MAXA; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXA; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }

    auto get_type = [&](int x) {
        // 1 -> value 1
        // prime p -> p^k
        // -1 -> at least two distinct prime factors
        if (x == 1) return 1;

        int first = spf[x];
        while (x % first == 0) x /= first;
        if (x == 1) return first;
        return -1;
    };

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        bool sorted_a = true;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] > a[i]) {
                sorted_a = false;
                break;
            }
        }
        if (sorted_a) {
            cout << "Bob\n";
            continue;
        }

        bool has_minus_one = false;
        for (int i = 0; i < n; i++) {
            b[i] = get_type(a[i]);
            if (b[i] == -1) has_minus_one = true;
        }

        if (has_minus_one) {
            cout << "Alice\n";
            continue;
        }

        bool sorted_b = true;
        for (int i = 1; i < n; i++) {
            if (b[i - 1] > b[i]) {
                sorted_b = false;
                break;
            }
        }

        if (sorted_b) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n";
        }
    }

    return 0;
}
