/*
Problem (LeetCode-style, paraphrased):
Given a string `s`, return the length of the longest substring that contains no repeating characters.

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Netflix, Adobe

Entry-level importance: High

Optimal approach used here:
- Sliding window with last-seen indices: expand `r`, and when a repeat is found, move `l` to `max(l, lastSeen[c] + 1)`.

Time complexity: O(n)
*/

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

    Solution sol;

    // Test case 1
    assert(sol.lengthOfLongestSubstring2("abcabcbb") == 3);

    // Test case 2
    assert(sol.lengthOfLongestSubstring2("bbbbb") == 1);

    cout << "All tests passed." << endl;

    return 0;
}