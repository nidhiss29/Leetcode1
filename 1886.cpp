class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        for (int i = 0; i != 4; ++i)
        {
            rotate(mat);
            if (mat == target)
            {
                return true;
            }
        }
        return false;
    }

    void rotate(vector<vector<int>> &mat)
    {
        auto new_mat = mat;
        const auto n = new_mat.size();
        const auto m = new_mat[0].size();
        for (int i = 0; i != n; ++i)
        {
            for (int j = 0; j != m; ++j)
            {
                new_mat[i][j] = mat[j][n - 1 - i];
            }
        }
        mat = move(new_mat);
    }
};