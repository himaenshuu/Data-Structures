/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 994. Rotting Oranges
 * Difficulty: Medium
 * LeetCode Link: https://leetcode.com/problems/rotting-oranges/
 *
 * PROBLEM STATEMENT:
 * Given an m x n grid where grid[i][j] = 0 (empty), 1 (fresh orange), or
 * 2 (rotten orange). Every minute, fresh oranges adjacent (4-directionally)
 * to rotten oranges become rotten. Return the minimum minutes until no fresh
 * oranges remain, or -1 if impossible. Constraints: m,n <= 10.
 *
 * Example:
 * Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
 * Output: 4 (all oranges rot after 4 minutes)
 *
 * APPROACH:
 * Algorithm: Multi-source Breadth-First Search (BFS)
 * Strategy: Start BFS from all rotten oranges simultaneously. Track time
 *           for each level of BFS (representing each minute). Fresh oranges
 *           adjacent to current rotten ones become rotten in the next level.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(m × n) - Visit each cell at most once during BFS
 * Space Complexity: O(m × n) - Queue can hold all cells in worst case
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Microsoft, Google, Meta, Apple
 * Tier 2 (Tech): Bloomberg, Adobe, Oracle, Uber, Goldman Sachs, Salesforce
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 5/5 - Essential
 * Why: Classic multi-source BFS problem with level-order traversal. Tests
 *      understanding of BFS timing and simultaneous spreading. Very common
 *      in entry-level interviews as it combines BFS with practical scenario.
 *
 * SIMILAR PROBLEMS: LC 286, LC 542, LC 1162, LC 1730, LC 417
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();

        queue<pair<int, int>> q;
        int fresh = 0;
        int minutes = 0;

        // find rotten and fresh oranges

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
                if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        // directions: up, down, left, right
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty() && fresh > 0)
        {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; i++)
            {
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;

                for (auto &d : dir)
                {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }
        return fresh == 0 ? minutes : -1;
    }
};
// T.C = O(rows X cols)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}};

    Solution obj;

    cout << "minutes are : " << obj.orangesRotting(v);
    return 0;
}