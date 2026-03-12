/*
Problem Statement:
Given an m x n integer matrix, if any cell is 0, set its entire row and column to 0. Do it in-place.

Difficulty Level:
Medium

Top Companies Asked:
Amazon, Microsoft, Google, Meta, Uber

Entry-Level Importance (0-2 YoE): 4/5

Early Intuition:
Directly zeroing rows/columns while scanning causes chain reactions. So first mark which rows/columns should become zero, then apply updates.

Optimal Approach:
Use first row and first column as marker arrays, plus two booleans for whether original first row/column had zero.
1) Scan first row and first column.
2) For remaining cells, mark row/column headers when zero found.
3) Zero marked cells.
4) Finally zero first row/column if needed.
Time: O(m*n), Space: O(1) extra.

Pseudo-code:
row0HasZero = any zero in row 0
col0HasZero = any zero in col 0
for i in [1..m-1], j in [1..n-1]:
    if matrix[i][j] == 0: matrix[i][0] = 0, matrix[0][j] = 0
for i in [1..m-1], j in [1..n-1]:
    if matrix[i][0] == 0 or matrix[0][j] == 0: matrix[i][j] = 0
if row0HasZero: zero row 0
if col0HasZero: zero col 0
*/

#include <bits/stdc++.h>
#include "utilities.h"
using namespace std;
typedef long long ll;
#define endl "\n"

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        // Create two variables which will store whether 1st row and 1st column
        // have 0 or not
        // use the first row and first column to store the value if the matrix
        // conatin 0 change the mark coordinates of the rows and columns to zero
        // check if 1st row & 1st column contained zero or not, if yes fill that with zero

        bool RowContainZero = false;
        bool ColumnContainZero = false;

        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < c; i++)
        {
            if (matrix[0][i] == 0)
                RowContainZero = true;
        }

        for (int i = 0; i < r; i++)
        {
            if (matrix[i][0] == 0)
                ColumnContainZero = true;
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (RowContainZero)
        { // fix the rows and traverse the columns
            for (int i = 0; i < c; i++)
            {
                matrix[0][i] = 0;
            }
        }

        if (ColumnContainZero)
        {
            for (int i = 0; i < r; i++)
            { // fix the column and traverse the rows
                matrix[i][0] = 0;
            }
        }
    }
};

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int j = 0; j < (int)row.size(); j++)
        {
            cout << row[j] << (j + 1 == (int)row.size() ? "" : " ");
        }
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Solution sol;

    vector<vector<int>> m1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    sol.setZeroes(m1);
    cout << "Test 1:" << endl;
    printMatrix(m1);

    vector<vector<int>> m2 = {
        {0, 1, 2, 0},
        {3, 4, 5, 2},
        {1, 3, 1, 5}};
    sol.setZeroes(m2);
    cout << "Test 2:" << endl;
    printMatrix(m2);

    vector<vector<int>> m3 = {
        {1, 2, 3},
        {4, 5, 6}};
    sol.setZeroes(m3);
    cout << "Test 3:" << endl;
    printMatrix(m3);

    return 0;
}