class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0])
        {
            return -1;
        }

        int n = grid.size();
        grid[0][0] = 1;

        queue<pair<int, int>> q;
        q.emplace(0, 0);

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();

            if (i == n - 1 and j == n - 1)
            {
                return grid[i][j];
            }

            for (int r = -1; r <= 1; r++)
            {
                for (int c = -1; c <= 1; c++)
                {
                    int ni = i + r, nj = j + c;
                    if (ni >= 0 and ni < n and nj >= 0 and nj < n and !grid[ni][nj])
                    {
                        grid[ni][nj] = grid[i][j] + 1;
                        q.emplace(ni, nj);
                    }
                }
            }
        }

        return -1;
    }
};