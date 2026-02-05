/*
Problem Statement: Climbing Stairs

You are climbing a staircase. It takes n steps to reach the top.
Each time you can climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

Constraints:
- 1 <= n <= 45

Companies Asked: Google, Meta, Amazon, Apple, Microsoft, Goldman Sachs

Approach: Dynamic Programming
Time Complexity: O(n)
Space Complexity: O(n) or O(1) with space optimization
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int findSteps(int n, vector<int> &dp)
    {
        if (n <= 1) // dp[0] = 1, bcoz the number of ways to climb 0 stairs is 1 way only.
            return 1;

        if (dp[n] != -1)
            return dp[n];

        return dp[n] = findSteps(n - 1, dp) + findSteps(n - 2, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 4;
    vector<int> dp(n + 1, -1);
    Solution sol;
    cout << sol.findSteps(n, dp) << endl;

    return 0;
}
