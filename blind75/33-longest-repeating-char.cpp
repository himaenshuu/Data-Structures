/*
Problem (LeetCode-style, paraphrased):
Given a string `s` (uppercase English letters) and an integer `k`, you may replace at most `k` characters in any substring. Return the length of the longest substring that can be made of the same repeating character after at most `k` replacements.

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Salesforce, TikTok

Entry-level importance: High

Optimal approach used here:
- Sliding window + frequency counts: keep `mf` = max frequency in the current window; if `(windowLen - mf) > k`, shrink from the left.

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
    int characterReplacement(string s, int k)
    {
        int n = s.size();
        int l = 0, r = 0, maxlen = 0;
        int mf = 0; // it will store the maximum frequency
        // traverse the string array with right = 0 -> n
        // store the frequency of each char,
        // check if it forms the valid window , if window size exceeds the value=k

        vector<int> freq(26, 0); // assuming the 0 based indexing
        
        for (int r = 0; r < n; r++)
        {
            freq[s[r] - 'A']++; //
            mf = max(mf, freq[s[r] - 'A']);

            while (r - l + 1 - mf > k) // check if window is valid
            {
                freq[s[l] - 'A']--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test case 1
    assert(sol.characterReplacement("ABAB", 2) == 4);

    // Test case 2
    assert(sol.characterReplacement("AABABBA", 1) == 4);

    cout << "All tests passed." << endl;

    return 0;
}