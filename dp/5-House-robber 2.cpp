/*
================================================================================
Problem Statement: House Robber II OR Maximum Sum of Non-Adjacent Elements (Circular Array)
LeetCode 213
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED: Google, Amazon, Microsoft, Meta, Apple, Bloomberg

PROBLEM STATEMENT:
You are a professional robber planning to rob houses along a street.
Each house has a certain amount of money stashed. All houses are arranged in a circle.
This means the first house is adjacent to the last one.

Adjacent houses have security systems connected, and it will automatically contact the police
if two adjacent houses are broken into on the same night.

Task:
Given an integer array `nums` representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

OR

Given a circular array of integers, find the maximum sum of non-adjacent elements.
You cannot select two consecutive elements. Additionally, the first and last elements
are considered adjacent (circular constraint).

Example 1:
Input: nums = [2, 3, 2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
because they are adjacent in the circle. Rob house 2 (money = 3) instead.

Example 2:
Input: nums = [1, 2, 3, 1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount = 1 + 3 = 4.

Example 3:
Input: nums = [1, 2, 3]
Output: 3

Constraints:
- 1 <= nums.length <= 100
- 0 <= nums[i] <= 1000

Approach (DP - Divide into Two Cases):
Since houses are in a circle, house[0] and house[n-1] are adjacent.
We cannot rob both of them.

Two cases:
1. Rob houses from index 0 to n-2 (include first, exclude last)
2. Rob houses from index 1 to n-1 (exclude first, include last)

For each case, apply House Robber I logic (max sum of non-adjacent elements).
Return max of both cases.

Time Complexity: O(n)
Space Complexity: O(n) or O(1) with space optimization
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// Divide into two cases:
// Case 1: Rob houses [0, n-2] (include first, exclude last)
// Case 2: Rob houses [1, n-1] (exclude first, include last)
// Return max of both cases

class Solution
{
public:
    int fun(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return arr[0];

        if (n == 2)
            return max(arr[0], arr[1]);

        vector<int> dp1(n, -1);
        dp1[0] = arr[0];
        dp1[1] = max(arr[0], arr[1]);

        // dp[i] is storing the value of max sum possible upto i

        for (int i = 2; i < n - 1; i++)
        {
            dp1[i] = max(arr[i] + dp1[i - 2], dp1[i - 1]);
        }

        vector<int> dp2(n, -1);
        dp2[1] = arr[1];
        dp2[2] = max(arr[2], arr[1]);

        for (int i = 3; i < n; i++)
        {
            dp2[i] = max(arr[i] + dp2[i - 2], dp2[i - 1]);
        }

        return max(dp2[n - 1], dp1[n - 2]);
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    Solution obj;
    cout << obj.fun(v) << endl;
    return 0;
}

// space optimized solution-O(1)

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int robCircular(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(
            robLinear(nums, 0, n - 2),
            robLinear(nums, 1, n - 1));
    }

    int robLinear(vector<int> &nums, int start, int end)
    {
        int prev2 = 0, prev1 = 0;
        for (int i = start; i <= end; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
