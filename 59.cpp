class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {

        vector<vector<int>> mat(n, vector<int>(n));

        int limit = n * n;
        bool r = false;
        bool u = false;
        bool d = false;
        bool l = false;
        int x = 0;
        int y = 0;
        int v = 1;
        for (int i = 0; i < limit; i++)
        {
            mat[x][y] = v++;
            if (r)
            {
                if (y < n - 1 - x)
                    y++;
                else
                    x++, r = false, d = true;
            }
            else if (d)
            {
                if (x < y)
                    x++;
                else
                    y--, d = false, l = true;
            }
            else if (l)
            {
                if (y > n - 1 - x)
                    y--;
                else
                    x--, l = false, u = true;
            }
            else
            {
                if (x > y + 1)
                    x--;
                else
                    y++, u = false, r = true;
            }
        }

        return mat;
    }
};