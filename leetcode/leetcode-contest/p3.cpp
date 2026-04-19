class Solution
{
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>> &sources)
    {
        vector<vector<int>> ans(n, vector<int>(m, 0));
        vector<vector<int>> d(n, vector<int>(m, -1));

        if (sources.empty())
            return ans;

        queue<pair<int, int>> q;
        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        for (auto &s : sources)
        {
            int r = s[0], c = s[1], col = s[2];
            if (d[r][c] == -1)
            {
                d[r][c] = 0;
                ans[r][c] = col;
                q.push({r, c});
            }
            else
            {
                ans[r][c] = max(ans[r][c], col);
            }
        }

        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nr = r + dr[k], nc = c + dc[k];
                if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                if (d[nr][nc] == -1)
                {
                    d[nr][nc] = d[r][c] + 1;
                    ans[nr][nc] = ans[r][c];
                    q.push({nr, nc});
                }
                else if (d[nr][nc] == d[r][c] + 1)
                {
                    ans[nr][nc] = max(ans[nr][nc], ans[r][c]);
                }
            }
        }

        return ans;
    }
};
