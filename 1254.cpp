class Solution
{
public:
    int rowchild[4] = {1, -1, 0, 0};
    int colchild[4] = {0, 0, 1, -1};

    int row, col;

    bool dfs(int x, int y, vector<vector<int>> &grid, vector<vector<bool>> &visited)
    {
        visited[x][y] = true;
        bool res = true;
        int px, py;

        for (int k = 0; k < 4; k++)
        {
            px = x + rowchild[k];
            py = y + colchild[k];

            if (px >= 0 && px < row && py >= 0 && py < col)
            {
                // update result from result of DFS call of neighbor node
                if (grid[px][py] == 0 && !visited[px][py])
                    res &= dfs(px, py, grid, visited);
            }
            else
                res = false;
        }
        return res;
    }

    int closedIsland(vector<vector<int>> &grid)
    {

        row = grid.size();
        col = grid[0].size();

        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int c = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == 0 && !visited[i][j])
                {
                    if (dfs(i, j, grid, visited))
                        c++;
                }
            }
        }
        return c;
    }
};