/*
Problem (LeetCode-style, paraphrased):
You are given an n x n 2D matrix. Rotate the matrix 90 degrees clockwise in-place (do not allocate another matrix for the result).

Difficulty: Medium

Companies (commonly reported; varies by source/time):
Amazon, Microsoft, Google, Meta, Apple, Bloomberg, Uber, LinkedIn, Salesforce, Adobe

Entry-level importance: High

Optimal approach used here:
- Transpose the matrix (swap across the main diagonal), then reverse each row.

Time complexity: O(n^2)
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each rows
        for (int i = 0; i < n; i++)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    // Test case 1: 2x2
    {
        vector<vector<int>> m = {{1, 2}, {3, 4}};
        sol.rotate(m);
        assert((m == vector<vector<int>>{{3, 1}, {4, 2}}));
    }

    // Test case 2: 3x3
    {
        vector<vector<int>> m = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        sol.rotate(m);
        assert((m == vector<vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}));
    }

    cout << "All tests passed." << endl;

    return 0;
}