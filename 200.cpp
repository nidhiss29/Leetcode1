class Solution
{
public:
    map<pair<int, int>, int> mark;

    int dfs(vector<vector<char>> &grid, int i, int j, int num)
    {
        mark[{i, j}] = num;
        if (i - 1 >= 0 && mark[{i - 1, j}] == 0 && grid[i - 1][j] == '1')
        {
            dfs(grid, i - 1, j, num);
        }

        if (j - 1 >= 0 && mark[{i, j - 1}] == 0 && grid[i][j - 1] == '1')
        {
            dfs(grid, i, j - 1, num);
        }

        if (i + 1 < grid.size() && mark[{i + 1, j}] == 0 && grid[i + 1][j] == '1')
        {
            dfs(grid, i + 1, j, num);
        }

        if (j + 1 < grid[0].size() && mark[{i, j + 1}] == 0 && grid[i][j + 1] == '1')
        {
            dfs(grid, i, j + 1, num);
        }

        return 0;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int num = 1, c = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (mark[{i, j}] == 0 && grid[i][j] == '1')
                {
                    dfs(grid, i, j, num);
                    num++;
                    c++;
                }
            }
        }
        return c;
    }
};