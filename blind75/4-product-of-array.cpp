/*
Problem: Product of Array Except Self (LeetCode #238)
Difficulty: Medium
Top Companies: Amazon, Meta, Microsoft, Apple, Google
Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
You cannot use division. Instead, for each index i, the answer is the product
of all elements to the left of i multiplied by all elements to the right.
Compute a prefix product array left-to-right, then multiply by suffix products
right-to-left in a second pass — total O(n) time and O(1) extra space.
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