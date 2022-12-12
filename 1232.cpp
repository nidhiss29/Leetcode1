class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &c)
    {
        double y = (c[1][1] - c[0][1]);
        double x = (c[1][0] - c[0][0]);
        double slope = x == 0 ? DBL_MAX : y / x;

        for (int i = 1; i < c.size() - 1; ++i)
        {
            y = (c[i + 1][1] - c[i][1]);
            x = (c[i + 1][0] - c[i][0]);
            double newSlope = x == 0 ? DBL_MAX : y / x;
            if (slope != newSlope)
                return false;
        }
        return true;
    }
};