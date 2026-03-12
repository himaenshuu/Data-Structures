/*
Problem: Two Sum (LeetCode #1)
Difficulty: Easy
Top Companies: Amazon, Google, Meta, Microsoft, Adobe, Apple, Bloomberg
Entry-Level Importance (0-2 YoE): 5/5

Problem Statement:
Given an array of integers nums and an integer target, return the indices of the
two numbers that add up to target. Each input has exactly one solution and you
may not use the same element twice.

Early Intuition:
For each number you visit, its required partner is (target - number).
Instead of a brute-force nested loop, store each number in a hash map keyed
by its value. On each step, check if the complement already exists — if yes,
return both indices immediately.

Optimal Approach:
Single-pass hash map. Iterate once; for each nums[i] check if (target - nums[i])
is already in the map. If yes, return {map[target-nums[i]], i}. Otherwise store
nums[i] -> i in the map. Time: O(n), Space: O(n).
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
#include "utilities.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> mp; 
        for (int i = 0; i < nums.size(); i++) 
        {
            mp[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int comp = target - nums[i];
            if (mp.find(comp) != mp.end())
            {
                return {i, mp[comp]};
            }
        }
        return {};
    }
};
// t.c = O(n)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout << "" << endl;
    Solution sol;
    vector<int> v = {2, 3, 4, 5};
    int target = 6;

    print1darray(sol.twoSum(v, target));
    return 0;
}
