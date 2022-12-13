class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        vector<vector<int>> dp = matrix;

        int ans = INT_MAX;
        for (int r = 1; r < dp.size(); r++)
        {
            dp[r][0] = matrix[r][0] + min({dp[r - 1][0], dp[r - 1][1]});

            for (int c = 1; c < dp[r].size() - 1; c++)
                dp[r][c] = matrix[r][c] + min({dp[r - 1][c], dp[r - 1][c - 1], dp[r - 1][c + 1]});

            int lc = dp[r].size() - 1;
            dp[r][lc] = matrix[r][lc] + min({dp[r - 1][lc], dp[r - 1][lc - 1]});
        }

        ans = *min_element(dp[dp.size() - 1].begin(), dp[dp.size() - 1].end());
        return ans;
    }
};