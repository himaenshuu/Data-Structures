/*
================================================================================
Frog Jump (Dynamic Programming - Tabulation)
================================================================================

DIFFICULTY: Easy ⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Google
- Adobe
- Flipkart
- Samsung

PROBLEM STATEMENT:
A frog is on stone 0 and wants to reach stone N-1. The frog can jump one or
two stones at a time. The cost of jumping from stone i to j is |height[i] - height[j]|.

Find the minimum total cost for the frog to reach the last stone.

CONSTRAINTS:
- 1 <= N <= 10^5
- 1 <= heights[i] <= 10^4

EXAMPLE:
Input: heights = [10, 20, 30, 10]
Output: 20
Explanation: 10 -> 20 -> 10 (cost = 10 + 10 = 20)

DYNAMIC PROGRAMMING APPROACH (Tabulation):
- dp[i] = minimum cost to reach stone i
- dp[0] = 0 (starting position)
- dp[1] = |heights[1] - heights[0]|
- For i >= 2:
  dp[i] = min(dp[i-1] + |heights[i] - heights[i-1]|,
              dp[i-2] + |heights[i] - heights[i-2]|)

TIME COMPLEXITY: O(n)
SPACE COMPLEXITY: O(n)

Can be optimized to O(1) space using variables instead of array!

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

// Using tabulation
class Solution
{
public:
    int frogJump(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        dp[1] = abs(heights[0] - heights[1]);

        for (int i = 2; i < n; i++)
        {
            int onestep = dp[i - 1] + abs(heights[i] - heights[i - 1]);
            int twostep = dp[i - 2] + abs(heights[i] - heights[i - 2]);

            dp[i] = min(onestep, twostep);
        }
        return dp[n - 1];
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
    cout << obj.frogJump(v) << endl;

    return 0;
}
