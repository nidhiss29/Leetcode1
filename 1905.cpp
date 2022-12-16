class Solution
{
public:
    void dfs(int x, int y, vector<vector<int>> &grid1, vector<vector<int>> &grid2, bool &chk)
    {
        if (x < 0 || x >= grid1.size() || y < 0 || y >= grid1[0].size())
        {
            return;
        }
        if (grid1[x][y] == 0 && grid2[x][y] == 1)
        {
            chk = false;
        }
        if (grid2[x][y] == 0)
        {
            return;
        }
        grid2[x][y] = 0;
        dfs(x - 1, y, grid1, grid2, chk);
        dfs(x, y - 1, grid1, grid2, chk);
        dfs(x + 1, y, grid1, grid2, chk);
        dfs(x, y + 1, grid1, grid2, chk);
    }
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        vector<vector<int>> v(grid1.size(), vector<int>(grid1[0].size(), 0));
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++)
        {
            for (int j = 0; j < grid2[0].size(); j++)
            {
                if (grid2[i][j] == 1)
                {
                    bool chk = true;
                    dfs(i, j, grid1, grid2, chk);
                    ans += chk;
                }
            }
        }
        return ans;
    }
};