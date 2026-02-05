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