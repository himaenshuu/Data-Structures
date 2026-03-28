#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        // Use string as a stack for minimal overhead.
        string st;
        st.reserve(n);

        for (char c : s) {
            if (!st.empty() && st.back() == c) {
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }

        cout << (st.empty() ? "YES" : "NO") << '\n';
    }

    return 0;
}
