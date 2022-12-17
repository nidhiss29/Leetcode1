class Solution
{
public:
    vector<int> findBall(vector<vector<int>> &G)
    {
        int m = G.size(), n = G[0].size();
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            int c = j;
            for (int i = 0; i < m; i++)
            {
                if (G[i][c] == 1)
                {
                    if (c == n - 1 || G[i][c + 1] == -1)
                        c = -1;
                    else if (G[i][c + 1] == 1)
                        c++;
                }
                else if (G[i][c] == -1)
                {
                    if (c == 0 || G[i][c - 1] == 1)
                        c = -1;
                    else if (G[i][c - 1] == -1)
                        c--;
                }
                if (c == -1)
                    break;
            }
            v.push_back(c);
        }
        return v;
    }
};