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