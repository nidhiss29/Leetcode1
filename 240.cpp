class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int sz = matrix.size();
        int len = matrix[0].size();

        int r = sz - 1, c = 0;

        while (r >= 0 and c < len)
        {
            if (matrix[r][c] == target)
                return true;
            else if (matrix[r][c] < target)
                c++;
            else
                r--;
        }
        return false;
    }
};