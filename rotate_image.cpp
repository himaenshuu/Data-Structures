/*
================================================================================
LeetCode #48 - Rotate Image
================================================================================

DIFFICULTY: Medium ⭐⭐

COMPANIES ASKED:
- Amazon
- Microsoft
- Apple
- Facebook
- Google
- Adobe
- Bloomberg
- Uber
- Oracle

PROBLEM STATEMENT:
You are given an n x n 2D matrix representing an image.
Rotate the image 90 degrees clockwise IN-PLACE.

You must modify the input 2D array in-place, without allocating another 2D array.

CONSTRAINTS:
- n == matrix.length == matrix[i].length
- 1 <= n <= 20
- -1000 <= matrix[i][j] <= 1000

EXAMPLE 1:
Input: matrix = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
Output: [[7,4,1],
         [8,5,2],
         [9,6,3]]

EXAMPLE 2:
Input: matrix = [[5,1],
                 [2,3]]
Output: [[2,5],
         [3,1]]

APPROACH: Transpose + Reverse (Optimal)
Step 1: Transpose the matrix
        - Swap elements across the diagonal (matrix[i][j] <-> matrix[j][i])
        - This converts rows to columns

Step 2: Reverse each row
        - Reverse all elements in each row left to right

Result: Matrix rotated 90 degrees clockwise

EXAMPLE WALKTHROUGH:
Original:  [[1,2,3],      Transpose:  [[1,4,7],      Reverse:  [[7,4,1],
            [4,5,6],   →              [2,5,8],   →            [8,5,2],
            [7,8,9]]                  [3,6,9]]                 [9,6,3]]

TIME COMPLEXITY: O(n²) - We visit each element once for transpose and once for reverse
SPACE COMPLEXITY: O(1) - In-place modification, no extra space used

================================================================================
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

vector<vector<int>> rotate_image(vector<vector<int>> &nums)
{
    int n = nums.size();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
                swap(nums[i][j], nums[j][i]);
        }
    }

    for (int j = 0; j < n; j++)
    {
        reverse(nums[j].begin(), nums[j].end());
    }

    return nums;
}

// total t.c = O(n^2)

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> v1 = rotate_image(v);

    for (const auto &row : v1)
    {
        for (auto el : row)
        {
            cout << el << " ";
        }
        cout << endl;
    }

    return 0;
}