class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> DP(n, 1);

        for (int r = 1; r < m; r++)
        {
            for (int c = 1; c < n; c++)
            {
                DP[c] += DP[c - 1];
            }
        }
        return DP[n - 1];
    }
};