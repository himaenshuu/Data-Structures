#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findValidElements(vector<int>& a) {
        int n = a.size();
        if (!n) return {};

        vector<int> suf(n);
        suf[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = max(a[i], suf[i + 1]);
        }

        vector<int> res;
        res.reserve(n);
        int lmx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            bool left = (i == 0) || (a[i] > lmx);
            bool right = (i == n - 1) || (a[i] > suf[i + 1]);
            if (left || right) res.push_back(a[i]);
            lmx = max(lmx, a[i]);
        }
        return res;
    }
};
