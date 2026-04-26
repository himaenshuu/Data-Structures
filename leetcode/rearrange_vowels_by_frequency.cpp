#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortVowelsByFrequency(string s) {
        const string v = "aeiou";
        vector<int> cnt(5), first(5, INT_MAX);

        for (int i = 0; i < (int)s.size(); ++i) {
            int x = id(s[i]);
            if (x == -1) continue;
            ++cnt[x];
            first[x] = min(first[x], i);
        }

        vector<int> ord;
        for (int i = 0; i < 5; ++i) {
            if (cnt[i]) ord.push_back(i);
        }

        sort(ord.begin(), ord.end(), [&](int a, int b) {
            if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
            return first[a] < first[b];
        });

        string t;
        for (int i : ord) t.append(cnt[i], v[i]);

        int j = 0;
        for (char &c : s) {
            if (id(c) != -1) c = t[j++];
        }
        return s;
    }

private:
    int id(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        if (c == 'u') return 4;
        return -1;
    }
};
