/*
Problem (LeetCode-style, paraphrased):
Given an array of strings, group the strings that are anagrams of each other. You may return the groups in any order.

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Uber, Bloomberg, LinkedIn, Airbnb, Stripe

Entry-level importance: High

Optimal approach used here:
- Use a hash map keyed by a canonical signature for each word (here: the sorted characters). Append each original word to its key's bucket.

Time complexity: O(N * K log K), where N = number of strings and K = max string length
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;
        // I will put all the anagrams of a kind in map
        // Then i will copy it to 2d vector and return the answer
        for (auto word : strs)
        {
            string x = word;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>> ans;
        for (auto &words : mp)
        {
            ans.push_back(words.second);
        }

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto normalize = [](vector<vector<string>> groups)
    {
        for (auto &g : groups)
        {
            sort(g.begin(), g.end());
        }
        sort(groups.begin(), groups.end());
        return groups;
    };

    Solution sol;

    // Test case 1
    {
        vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        auto got = normalize(sol.groupAnagrams(strs));
        vector<vector<string>> expected = {{"ate", "eat", "tea"}, {"bat"}, {"nat", "tan"}};
        assert(got == normalize(expected));
    }

    // Test case 2
    {
        vector<string> strs = {"", "", "b"};
        auto got = normalize(sol.groupAnagrams(strs));
        vector<vector<string>> expected = {{"", ""}, {"b"}};
        assert(got == normalize(expected));
    }

    cout << "All tests passed." << endl;

    return 0;
}