/*
================================================================================
LeetCode #198 - House Robber OR Maximum Sum of Non-Adjacent Elements
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Facebook
- Apple
- Adobe
- Bloomberg
- LinkedIn
- Uber
- Goldman Sachs

PROBLEM STATEMENT:
You are a robber planning to rob houses along a street. Each house has a
certain amount of money. Adjacent houses have security systems that will alert
police if two adjacent houses are broken into on the same night.

Given an integer array nums representing the amount of money of each house,
return the maximum amount of money you can rob tonight without alerting the police.

OR

Given an array of integers, find the maximum sum of non-adjacent elements.
You cannot select two consecutive elements.

CONSTRAINTS:
- 1 <= nums.length <= 100
- 0 <= nums[i] <= 400

EXAMPLE 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (1) and house 3 (3). Total = 1 + 3 = 4

EXAMPLE 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (2), house 3 (9), and house 5 (1). Total = 2 + 9 + 1 = 12

DYNAMIC PROGRAMMING APPROACH:
- dp[i] = maximum sum possible up to index i
- dp[0] = arr[0]
- dp[1] = max(arr[0], arr[1])
- dp[i] = max(arr[i] + dp[i-2], dp[i-1])
  (either take current + skip adjacent, OR skip current)

APPROACH 1 (fun): O(n) time, O(n) space
APPROACH 2 (maxNonAdjacentSum): O(n) time, O(1) space ⭐ OPTIMAL

Space optimization using prev2, prev1 instead of array!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"
class Solution
{
public:
    int fun(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 1)
            return arr[0];

        vector<int> dp(n, -1);
        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);

        // dp[i] is storing the value of max sum possible upto i

        for (int i = 2; i < n; i++)
        {
            dp[i] = max(arr[i] + dp[i - 2], dp[i - 1]);
        }

        return dp[n - 1];
    }
};

// Space optimized O(1)
int maxNonAdjacentSum(vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return arr[0];

    int prev2 = arr[0], prev1 = max(arr[0], arr[1]);
    for (int i = 2; i < n; i++)
    {
        int curr = max(arr[i] + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

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
