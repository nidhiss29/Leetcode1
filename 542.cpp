class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        if (mat.empty() || mat[0].empty())
            return mat;
        int M = mat.size(), N = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < M; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (!mat[i][j])
                    q.emplace(i, j);
                else
                    mat[i][j] = INT_MAX;
            }
        }
        int dirs[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (q.size())
        {
            auto p = q.front();
            q.pop();
            for (auto dir : dirs)
            {
                int x = p.first + dir[0], y = p.second + dir[1];
                if (x >= 0 && x < M && y >= 0 && y < N && mat[x][y] == INT_MAX)
                {
                    mat[x][y] = mat[p.first][p.second] + 1;
                    q.emplace(x, y);
                }
            }
        }
        return mat;
    }
};

// https://leetcode.com/problems/01-matrix/discuss/101093/C%2B%2B-BFS-Greedy