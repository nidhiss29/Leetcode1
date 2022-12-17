class Solution
{
public:
    vector<vector<int>> dir{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxDistance(vector<vector<int>> &grid)
    {

        int m = grid.size(), n = grid[0].size(), dist = -1;

        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                }
            }
        }

        while (!q.empty())
        {
            auto cur = q.front();

            q.pop();

            for (auto &x : dir)
            {
                int a = cur.first + x[0];
                int b = cur.second + x[1];

                if (a >= 0 && b >= 0 && a < m && a < n && grid[a][b] == 0)
                {
                    grid[a][b] = grid[cur.first][cur.second] + 1;

                    dist = max(dist, grid[a][b]);

                    q.push({a, b});
                }
            }
        }

        return dist == -1 ? -1 : dist - 1;
    }
};