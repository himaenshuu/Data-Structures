/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 542. 01 Matrix
 * Difficulty: Medium
 * LeetCode Link: https://leetcode.com/problems/01-matrix/
 *
 * PROBLEM STATEMENT:
 * Given an m x n binary matrix mat, return the distance of the nearest 0
 * for each cell. The distance between two adjacent cells is 1. Constraints:
 * m,n <= 10^4, mat[i][j] is either 0 or 1.
 *
 * Example:
 * Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
 * Output: [[0,0,0],[0,1,0],[1,2,1]]
 *
 * APPROACH:
 * Algorithm: Multi-source Breadth-First Search (BFS)
 * Strategy: Start BFS from all cells with 0 simultaneously. For each cell
 *           with value 1, its distance is calculated as 1 + distance of
 *           nearest visited neighbor. BFS guarantees shortest distance.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(m × n) - Visit each cell at most once
 * Space Complexity: O(m × n) - Queue can hold all cells in worst case
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Amazon, Google, Microsoft, Meta, Apple
 * Tier 2 (Tech): Bloomberg, Adobe, Oracle, Uber, Salesforce, LinkedIn
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 4/5 - Highly Recommended
 * Why: Important multi-source BFS variant demonstrating shortest path
 *      computation in grids. Tests understanding of BFS distance tracking.
 *      Common in mid-level technical interviews.
 *
 * SIMILAR PROBLEMS: LC 994, LC 286, LC 1162, LC 1765, LC 2146
 *
 * DATE SOLVED: 2026-03-23
 * LAST REVIEWED: 2026-03-23
 ******************************************************************************/

#include <bits/stdc++.h>
#include "../utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int, int>> q;

        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // find position of zero and push it to queue
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }

        while (!q.empty())
        {
            auto p = q.front();
            int x = p.first;
            int y = p.second;

            q.pop();

            for (auto &d : dir)
            {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && mat[nx][ny] == -1)
                {
                    mat[nx][ny] = mat[x][y] + 1;
                    q.push({nx, ny}); // we pushed its position because yahan tak ham pahunch chueke h at time t=t
                }
            }
        }
        return mat;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution obj;
    vector<vector<int>> v = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}};

    vector<vector<int>> v1 = obj.updateMatrix(v);
    print2darray(v1);

    return 0;
}