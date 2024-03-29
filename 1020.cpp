class Solution
{
private:
    void dfs(vector<vector<int>> &grid, int r, int c, int rows, int cols)
    {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 1)
            return;

        grid[r][c] = 2;

        dfs(grid, r + 1, c, rows, cols);
        dfs(grid, r - 1, c, rows, cols);
        dfs(grid, r, c + 1, rows, cols);
        dfs(grid, r, c - 1, rows, cols);
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        int result = 0;

        for (int r = 0; r < rows; r++)
        {
            if (grid[r][0] == 1)
            {
                dfs(grid, r, 0, rows, cols);
            }
        }

        for (int c = 0; c < cols; c++)
        {
            if (grid[0][c] == 1)
            {
                dfs(grid, 0, c, rows, cols);
            }
        }

        for (int r = 0; r < rows; r++)
        {
            if (grid[r][cols - 1] == 1)
            {
                dfs(grid, r, cols - 1, rows, cols);
            }
        }

        for (int c = 0; c < cols; c++)
        {
            if (grid[rows - 1][c] == 1)
            {
                dfs(grid, rows - 1, c, rows, cols);
            }
        }

        for (int r = 1; r < rows - 1; r++)
        {
            for (int c = 1; c < cols - 1; c++)
            {
                if (grid[r][c] == 1)
                {
                    result++;
                }
            }
        }

        return result;
    }
};