#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool isValid(string s)
    {

        unordered_map<char, char> mp = {{'(', ')'}, {'{', '}'}, {'[', ']'}};

        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {

            if (mp.find(s[i]) != mp.end())
            {
                st.push(s[i]);
                continue;
            }
            if (st.empty())
            {
                return false;
            }

            char ch = st.top();
            st.pop();
            if (s[i] == mp[ch])
                continue;
            else
                return false;
        }
        return st.empty() ? true : false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;

    return 0;
}