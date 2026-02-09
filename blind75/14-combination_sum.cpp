/*
================================================================================
Problem: LeetCode 39 - Combination Sum OR Find All Subsets That Sum to Target (With Repetition)
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED: Amazon, Microsoft, Meta, Google, Apple, Adobe, Bloomberg

PROBLEM STATEMENT (Version 1):
Given an array of distinct integers `candidates` and a target integer `target`,
return all unique combinations of `candidates` where the chosen numbers sum to `target`.
You may use each candidate an unlimited number of times. Combinations must be unique,
and the order of numbers within a combination does not matter.
If there is no valid combination, return an empty list.

OR

PROBLEM STATEMENT (Version 2):
Given a set of distinct positive integers and a target sum, find all possible
combinations of numbers that add up to the target. Each number can be used
multiple times (unlimited repetition allowed). Return all unique combinations.

Example 1:
Input: candidates = [2, 3, 6, 7], target = 7
Output: [[2, 2, 3], [7]]
Explanation:
- 2 + 2 + 3 = 7
- 7 = 7

Example 2:
Input: candidates = [2, 3, 5], target = 8
Output: [[2, 2, 2, 2], [2, 3, 3], [3, 5]]
Explanation:
- 2 + 2 + 2 + 2 = 8
- 2 + 3 + 3 = 8
- 3 + 5 = 8

Example 3:
Input: candidates = [2], target = 1
Output: []
Explanation: No combination sums to 1.

Constraints:
- 1 <= candidates.length <= 30
- 2 <= candidates[i] <= 40
- All elements of candidates are distinct
- 1 <= target <= 40

Approach (Backtracking):
Use recursion with backtracking to explore all possible combinations.
At each step, either:
1. Include the current candidate (can use again)
2. Skip to the next candidate

Pruning: Stop when sum > target (optimization)

Time Complexity: O(2^target) - exponential in worst case
Space Complexity: O(target) - recursion depth

📚 For detailed Backtracking guide, see: backtracking.md

================================================================================
*/

#include <bits/stdc++.h>
#include "utilities.h"; using namespace std;
typedef long long ll;
#define endl "\n"

/*
Here we use backtracking not the dp because here we are asked to find the all combinations possible
*/

class Solution
{
private:
    void findCombination(int index, int target, vector<int> &arr,
                         vector<vector<int>> &ans, vector<int> ds)
    {
        if (index == arr.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[index] <= target)
        {
            ds.push_back(arr[index]);
            findCombination(index, target - arr[index], arr, ans, ds);
            ds.pop_back();
        }

        findCombination(index + 1, target, arr, ans, ds);
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);

        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vect = {2, 3, 6, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> v = sol.combinationSum(vect, target);
    print2darray(v);

    return 0;
}