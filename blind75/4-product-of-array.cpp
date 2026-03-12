/*
Problem: Product of Array Except Self (LeetCode #238)
Difficulty: Medium
Top Companies: Amazon, Meta, Microsoft, Apple, Google
Entry-Level Importance (0-2 YoE): 4/5

Problem Statement:
Given an integer array nums, return an array answer such that answer[i] is equal
to the product of all elements of nums except nums[i]. Must run in O(n) without
using the division operator.

Early Intuition:
You cannot use division. Instead, for each index i, the answer is the product
of all elements to the left of i multiplied by all elements to the right.
Compute a prefix product array left-to-right, then multiply by suffix products
right-to-left in a second pass — total O(n) time and O(1) extra space.

Optimal Approach:
Pass 1 (left to right): fill result[i] with product of everything to its left.
Pass 2 (right to left): multiply result[i] by a running suffix product.
Time: O(n), Space: O(1) extra (output array not counted).
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums) // tc=O(n)
    {
        int p = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            p = p * nums[i];
        }

        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = p / nums[i];
        }

        return nums;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution sol;
    vector<int> vect = {2, 3, 4, 5};
    print1darray(sol.productExceptSelf(vect));
    cout << "" << endl;
    return 0;
}