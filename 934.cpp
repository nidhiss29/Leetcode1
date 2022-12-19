class Solution
{
public:
    void find(vector<vector<int>> &mat, int i, int j, vector<pair<int, int>> &v)
    {
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || mat[i][j] == 0)
        {
            return;
        }
        mat[i][j] = 0;
        v.push_back({i, j});
        find(mat, i - 1, j, v);
        find(mat, i + 1, j, v);
        find(mat, i, j - 1, v);
        find(mat, i, j + 1, v);
    }
    int shortestBridge(vector<vector<int>> &mat)
    {
        if (mat.empty())
        {
            return 0;
        }
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int, int>> v1, v2;
        int f = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (f == 1)
                    {
                        f = 0;
                        find(mat, i, j, v1);
                    }
                    else
                    {
                        find(mat, i, j, v2);
                    }
                }
            }
        }
        int dis = INT_MAX;
        for (auto it1 : v1)
        {
            for (auto it2 : v2)
            {
                int x1 = it1.first;
                int y1 = it1.second;
                int x2 = it2.first;
                int y2 = it2.second;
                int d = abs(x1 - x2) + abs(y1 - y2);
                dis = min(d, dis);
            }
        }
        return dis - 1;
    }
};