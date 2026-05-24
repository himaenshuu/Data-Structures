/******************************************************************************
 * LEETCODE PROBLEM
 ******************************************************************************/
/*
 * Problem: 733. Flood Fill
 * Difficulty: Easy
 * LeetCode Link: https://leetcode.com/problems/flood-fill/
 *
 * PROBLEM STATEMENT:
 * Given an m x n image represented by a 2D integer grid where image[i][j]
 * represents the pixel value. Starting from pixel (sr, sc), perform a flood
 * fill: change the starting pixel and all connected pixels of the same color
 * to the new color. Two pixels are connected if they are adjacent
 * 4-directionally. Constraints: m,n <= 50.
 *
 * Example:
 * Input: image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2
 * Output: [[2,2,2],[2,2,0],[2,0,1]]
 *
 * APPROACH:
 * Algorithm: DFS (Recursive) or BFS (Iterative)
 * Strategy: Starting from (sr, sc), recursively/iteratively visit all
 *           4-directionally connected pixels with the same original color
 *           and change them to the new color. Handle edge case where
 *           original color equals new color.
 *
 * COMPLEXITY ANALYSIS:
 * Time Complexity: O(m × n) - In worst case, visit all pixels
 * Space Complexity: O(m × n) - Recursion stack or queue in worst case
 *
 * COMPANIES (Asked in interviews):
 * Tier 1 (FAANG+): Google, Microsoft, Amazon, Meta, Apple
 * Tier 2 (Tech): Adobe, Bloomberg, Uber, Oracle, Salesforce, LinkedIn
 *
 * ENTRY LEVEL IMPORTANCE:
 * Rating: 5/5 - Essential
 * Why: Fundamental graph traversal problem teaching DFS/BFS basics. Classic
 *      introduction to connected components and 2D grid traversal. Perfect
 *      entry-level problem that appears in 80% of junior interviews.
 *
 * SIMILAR PROBLEMS: LC 200, LC 695, LC 1254, LC 1020, LC 827
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
    void print2darray(vector<vector<int>> vect)
    {
        for (auto &row : vect)
        {
            for (auto &el : row)
            {
                cout << el << " ";
            }
            cout << endl;
        }
    }

    // Recursive
    void dfs(vector<vector<int>> &image, int x, int y, int original, int newColor, int rows, int cols)
    {
        if (x < 0 || y < 0 || x >= rows || y >= cols || image[x][y] != original)
            return;

        image[x][y] = newColor;

        dfs(image, x + 1, y, original, newColor, rows, cols); // down
        dfs(image, x - 1, y, original, newColor, rows, cols); // up
        dfs(image, x, y + 1, original, newColor, rows, cols); // right
        dfs(image, x, y - 1, original, newColor, rows, cols); // left
    }

    vector<vector<int>> floodFillrec(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int original = image[sr][sc];
        if (original != color)
        {
            dfs(image, sr, sc, original, color, image.size(), image[0].size());
        }
        return image;
    }

    // Iterative
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {

        int rows = image.size();
        int cols = image[0].size();

        // define direction right, left, up, down
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int original_color = image[sr][sc];
        if (original_color == color)
            return image; // No need to fill if same color

        queue<pair<int, int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;

        while (!q.empty())
        {
            int size = q.size();

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

                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && image[nx][ny] == original_color)
                    {
                        image[nx][ny] = color;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return image;
    }
};
// t.c = O(rows*cols)

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}};
    Solution obj;
    vector<vector<int>> v1 = obj.floodFill(v, 1, 1, 2);

    obj.print2darray(v1);

    return 0;
}