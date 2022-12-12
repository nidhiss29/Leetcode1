class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int i = 0, j = mat[0].size() - 1;
        int sum = 0;
        for (int k = 0; k < mat.size(); k++)
        {
            for (int c = 0; c < mat[0].size(); c++)
                if (c == i || c == j)
                    sum += mat[i][c];
            i += 1;
            j -= 1;
        }
        return sum;
    }
};