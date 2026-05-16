#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> scoreAndCounter(vector<string>& e) {
        int s = 0, c = 0;
        for (auto &x : e) {
            if (c == 10) break;
            if (x == "W") ++c;
            else if (x == "WD" || x == "NB") ++s;
            else s += x[0] - '0';
        }
        return {s, c};
    }
};