#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct BIT {
        int n; vector<int> t;
        BIT(int n=0): n(n), t(n+1,0) {}
        void upd(int i, int v){ for(++i;i<=n;i+=i&-i) t[i]=max(t[i],v); }
        int qry(int i){ int r=0; for(++i;i>0;i-=i&-i) r=max(r,t[i]); return r; }
    };
public:
    int maxFixedPoints(vector<int>& a) {
        int n = (int)a.size();
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            int x = a[i];
            if (0 <= x && x < n && x <= i) g[x].push_back(i - x);
        }

        BIT fw(n);
        int ans = 0;
        for (int x = 0; x < n; ++x) {
            if (g[x].empty()) continue;
            vector<pair<int,int>> add;
            add.reserve(g[x].size());
            for (int d : g[x]) {
                int v = fw.qry(d) + 1;
                add.push_back({d, v});
                ans = max(ans, v);
            }
            for (auto &p : add) fw.upd(p.first, p.second);
        }
        return ans;
    }
};
