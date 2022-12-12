class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int ny = nums.size(), nx = nums[0].size(), y = 0, x = -1;
        if (ny * nx != r * c)
            return nums;
        vector<vector<int>> mat(r, vector<int>(c)); // matrix r*c

        for (int rr = 0; rr < r; rr++)
            for (int cc = 0; cc < c; cc++)
            {
                if (++x == nx)
                {
                    x = 0;
                    y++;
                }
                mat[rr][cc] = nums[y][x];
            }

        return mat;
    }
};