/*
Problem: Contains Duplicate (LeetCode #217)
Difficulty: Easy
Top Companies: Amazon, Google, Bloomberg, Apple, Adobe
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given an integer array nums, return true if any value appears at least twice,
and false if every element is distinct.

Early Intuition:
Insert each element into a hash set one by one.
If an element is already in the set before you insert it, a duplicate exists.
This turns an O(n^2) brute-force comparison into a single O(n) pass.

Optimal Approach:
Iterate the array; on each element check membership in an unordered_set before
inserting. First hit returns true immediately; finishing the loop without a hit
returns false. Time: O(n), Space: O(n).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums) // O(nlogn)
    {
        sort(nums.begin(), nums.end()); // O(nlogn) bcoz of binary insertion
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i + 1] == nums[i])
                return true;
        }
        return false;
    }

    bool containsDuplicate1(vector<int> &nums) // O(n)
    {
        set<int> st;
        for (int i = 0; i < nums.size(); i++)
        {
            if (st.find(nums[i]) != st.end())
            {
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> vect = {5, 2, 1, 1};
    if (sol.containsDuplicate1(vect))
    {
        cout << "True" << endl;
    }
    else
        cout << "False" << endl;

    return 0;
}