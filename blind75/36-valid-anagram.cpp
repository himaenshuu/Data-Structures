/*
Problem (LeetCode-style, paraphrased):
Given two strings `s` and `t`, return true if `t` is an anagram of `s` (same characters with the same counts), otherwise return false.

Difficulty: Easy

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Bloomberg, Uber, LinkedIn, Salesforce, PayPal

Entry-level importance: High

Optimal approach used here:
- Count characters by incrementing for `s` and decrementing for `t`, then verify all counts return to zero.

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
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
            mp[t[i]]--;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp[s[i]] > 0)
                return false;
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test case 1
    assert(sol.isAnagram("anagram", "nagaram") == true);

    // Test case 2
    assert(sol.isAnagram("rat", "car") == false);

    cout << "All tests passed." << endl;

    return 0;
}