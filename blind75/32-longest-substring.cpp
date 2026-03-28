#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int lengthOfLongestSubstring1(string s)
    {
        int n = s.size();
        int ans = 0;

        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp.clear();
            for (int j = i; j < n; j++)
            {
                if (mp[s[j]] == 1)
                    break;
                mp[s[j]] = 1;

                int len = j - i + 1;
                ans = max(ans, len);
            }
        }
        return ans;
    }
    // tc=O(N^2)

    // sliding window + hash
    int lengthOfLongestSubstring2(string s)
    {
        int n = s.size();
        vector<int> hash(256, -1); // it will store the position of that char 

        int l = 0, r = 0, ans = 0;

        while (r < n)
        {
            if (hash[s[r]] != -1)
            {
                l = max(hash[s[r]] + 1, l);
            }

            int len = r - l + 1;
            ans = max(ans, len);

            hash[s[r]] = r;
            r++;
        }
        return ans;
    }
};
// tc=O(N)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    return 0;
}