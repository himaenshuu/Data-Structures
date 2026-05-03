/*
================================================================================
Problem: Ninja's Training OR Maximum Points with No Two Consecutive Same Tasks
Similar to: LeetCode 1911 - Maximum Alternating Subsequence Sum (variant concept)
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED: Amazon, Goldman Sachs, Adobe

PROBLEM STATEMENT (Version 1 - Ninja's Training):
A ninja is training for N days. Each day, the ninja can perform one of three activities:
- Activity 0: Running
- Activity 1: Fighting
- Activity 2: Learning

Each activity on day i gives points[i][j] merit points (where j = 0, 1, or 2).
The ninja cannot perform the same activity on two consecutive days.

Task:
Given a 2D array `points` of size N × 3, where points[i][j] represents merit points
for activity j on day i, find the maximum total merit points the ninja can earn
over N days.

OR

PROBLEM STATEMENT (Version 2 - Abstract DP):
You are given a 2D array of size N × 3, where each row represents a day and each column
represents a choice. On each day, you must pick exactly one choice, and you cannot pick
the same choice on two consecutive days.

Task:
Return the maximum sum you can achieve by selecting one element from each row such that
no two consecutive rows have selections from the same column.

Example 1:
Input:
points = [[1, 2, 5],
          [3, 1, 1],
          [3, 3, 3]]
Output: 11
Explanation:
Day 0: Choose activity 2 (Running) → 5 points
Day 1: Choose activity 0 (Fighting) → 3 points
Day 2: Choose activity 1 (Learning) → 3 points
Total = 5 + 3 + 3 = 11

Example 2:
Input:
points = [[10, 40, 70],
          [20, 50, 80],
          [30, 60, 90]]
Output: 210
Explanation: 70 + 50 + 90 = 210

Constraints:
- 1 <= N <= 100000
- 1 <= points[i][j] <= 100

Approach (DP - Memoization/Tabulation):
State: dp[day][last] = max points from day 0 to 'day' when last activity performed was 'last'
Transition: For each day, try all 3 activities except the last one performed
Base case: On day 0, pick the best activity that's not same as 'last'

Time Complexity: O(N × 3 × 3) = O(N)
Space Complexity: O(N × 4) = O(N) for memoization, O(1) with space optimization

================================================================================
*/

// Ninja's Training

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int fun(int day, int last, vector<vector<int>> &points, vector<vector<int>> dp)
    {

        if (day == 0){
            int maxi = 0;

            for (int task = 0; task < 3; task++){
                if (task != last){
                    maxi = max(maxi, points[0][task]);
                }
            }
            return maxi;
        }

        if (dp[day][last] != -1)
            return dp[day][last];

        int maxi = 0;

        for (int task = 0; task < 3; task++){
            if (task != last){
                int point = points[day][task] + fun(day - 1, task, points, dp);
                maxi = max(maxi, point);
            }
        }
        return dp[day][last] = maxi;
    }
    int ninjaTraining(vector<vector<int>> &points)
    {
        int n = points.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));

        return fun(n - 1, 3, points, dp);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> pts(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        cin >> pts[i][0] >> pts[i][1] >> pts[i][2];

    Solution obj;
    cout << obj.ninjaTraining(pts) << endl;

    return 0;
}
