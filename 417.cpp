class Solution
{
private:
    vector<int> dir{0, 1, 0, -1, 0};
    int m{0};
    int n{0};

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return {};
        }
        m = matrix.size();
        n = matrix[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            dfs(matrix, pacific, i, 0);
            dfs(matrix, atlantic, i, n - 1);
        }

        for (int j = 0; j < n; j++)
        {
            dfs(matrix, pacific, 0, j);
            dfs(matrix, atlantic, m - 1, j);
        }

        vector<vector<int>> res;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] and atlantic[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int row, int col)
    {
        visited[row][col] = true;

        for (int i = 0; i < 4; i++)
        {
            int nextRow = row + dir[i];
            int nextCol = col + dir[i + 1];
            if (nextRow >= 0 and nextRow < m and nextCol >= 0 and nextCol < n and !visited[nextRow][nextCol])
            {
                if (matrix[row][col] <= matrix[nextRow][nextCol])
                {
                    dfs(matrix, visited, nextRow, nextCol);
                }
            }
        }
    }
};