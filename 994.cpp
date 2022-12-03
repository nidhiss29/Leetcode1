// https://leetcode.com/problems/rotting-oranges/discuss/238579/C%2B%2BJava-with-picture-BFS

class Solution
{
public:
    bool isSafe(int x, int y, int R, int C)
    {
        if (x < 0 || x >= R || y < 0 || y >= C)
            return false;
        return true;
    }

    int orangesRotting(vector<vector<int>> &grid)
    {
        queue<pair<int, int>> q;
        int fresh = 0;
        int count = 0;
        int res = -1;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        int r = grid.size();
        int c = grid[0].size();

        int dirX[4] = {0, 0, -1, 1};
        int dirY[4] = {1, -1, 0, 0};

        while (!q.empty())
        {
            int n = q.size();
            if (n == 0)
                break;
            res++;
            while (n--)
            {
                pair<int, int> i = q.front();
                q.pop();

                int x = i.first;
                int y = i.second;

                for (int k = 0; k < 4; k++)
                {
                    int newX = x + dirX[k];
                    int newY = y + dirY[k];

                    if (isSafe(newX, newY, r, c) && grid[newX][newY] == 1)
                    {
                        count++;
                        grid[newX][newY] = 2;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return (count == fresh ? res : -1);
    }
};