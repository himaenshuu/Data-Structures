class Solution
{
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k)
    {
        for (int d = 0; d < k / 2; ++d)
        {
            int r1 = x + d;
            int r2 = x + k - 1 - d;
            for (int c = y; c < y + k; ++c)
                swap(grid[r1][c], grid[r2][c]);
        }
        return grid;
    }
};