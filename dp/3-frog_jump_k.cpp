/*
Problem Statement: Frog Jump (K Distance)

A frog wants to climb a staircase with n steps. Given an integer array heights, where heights[i] contains the height of the ith step, and an integer k. To jump from the ith step to the jth step, the frog requires abs(heights[i] - heights[j]) energy, where abs() denotes the absolute difference. The frog can jump from the ith step to any step in the range [i + 1, i + k], provided it exists. Return the minimum amount of energy required by the frog to go from the 0th step to the (n-1)th step.

Task:
Return the minimum total cost to reach stone n-1.

Example:
Input:
    n = 5
    heights = [10, 30, 40, 20, 10]
    k = 3
Output:
    20
Explanation:
    One optimal path is 0 -> 3 -> 4
    cost = |10-20| + |20-10| = 10 + 10 = 20

Constraints (typical):
- 1 <= n
- 1 <= k

Approach (DP - Tabulation):
dp[i] = minimum cost to reach stone i
dp[i] = min over j=1..k (dp[i-j] + |heights[i] - heights[i-j]|), when i-j >= 0

Time Complexity: O(n * k)
Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// frog_jump problem with k distances
class Solution
{
public:
    int fun(vector<int> &heights, int k)
    {
        int n = heights.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i && j <= k; j++)  // j is jump lenght 
            {
                dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
            }
        }
        return dp[n - 1];
    }
};

// TC = O(n*k) SC = O(n)

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int k;
    cin >> k;
    Solution obj;
    cout << obj.fun(v, k) << endl;

    return 0;
}
