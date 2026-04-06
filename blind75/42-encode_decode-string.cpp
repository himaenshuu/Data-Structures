#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        int n = strs.size();
        int num = 0;
        string r = "";

        for (int i = 0; i < n; i++)
        {
            int size = strs[i].size();
            r = r + to_string(size) + "$" + strs[i];
        }

        return r;
    }

    vector<string> decode(string s)
    {
        int n = s.size();
        vector<string> vect;
        string ans = "";

        for (int i = 0; i < n; i++)
        {
            ans += s[i];
            if (s[i] == '$')
            {
                ans.pop_back(); // used in string only
                int len = stoi(ans);
                vect.push_back(s.substr(i + 1, len));
                i = i + len;
                ans.clear(); // it becomes empty
            }
        }

        return vect;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;
    int failed = 0;

    auto runTest = [&](const string &name, const vector<string> &input)
    {
        vector<string> copy = input;
        string encoded = sol.encode(copy);
        vector<string> decoded = sol.decode(encoded);

        bool ok = (decoded == input);
        cout << name << ": " << (ok ? "PASSED" : "FAILED") << endl;
        if (!ok)
            failed++;
    };

    // Test case 1: normal strings
    runTest("TC1", {"lint", "code", "love"});

    // Test case 2: includes '$' delimiter inside strings + numbers
    runTest("TC2", {"$", "a$b$c", "123$456", ""});

    // Test case 3: empty + spaces + long string
    runTest("TC3", {"", " ", " with spaces ", string(50, 'x')});

    if (failed == 0)
        cout << "All tests passed." << endl;
    return failed == 0 ? 0 : 1;
}