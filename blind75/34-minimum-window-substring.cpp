/*
Problem (LeetCode-style, paraphrased):
Given strings `s` and `t`, return the smallest substring of `s` that contains all characters of `t` (including required multiplicities). If no such substring exists, return an empty string.

Difficulty: Hard

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Netflix, Airbnb

Entry-level importance: Medium

Optimal approach used here:
- Sliding window with a frequency array for required characters.
- Expand right pointer to satisfy requirements; once satisfied, shrink from the left to minimize.

Time complexity: O(|s| + |t|) (amortized linear in |s| with constant alphabet)
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    string minWindow(string s, string t)
    {
        vector<int> freq(128, 0);

        // Store required characters
        for (char c : t)
        {
            freq[c]++;
        }

        int l = 0, r = 0;
        int count = t.size(); // total characters needed

        int minLen = INT_MAX;
        int start = 0;

        while (r < s.size())
        {
            // If current char is needed, decrease count
            if (freq[s[r]] > 0)
            {
                count--;
            }

            freq[s[r]]--; // include character in window
            r++;

            // When all characters are matched
            while (count == 0)
            {
                // Update minimum window
                if (r - l < minLen)
                {
                    minLen = r - l;
                    start = l;
                }

                // Try to remove left character
                freq[s[l]]++;

                // If removing makes window invalid
                if (freq[s[l]] > 0)
                {
                    count++;
                }

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test case 1
    assert(sol.minWindow("ADOBECODEBANC", "ABC") == "BANC");

    // Test case 2
    assert(sol.minWindow("a", "aa") == "");

    cout << "All tests passed." << endl;

    return 0;
}