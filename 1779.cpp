class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int dist = -1, ind = -1;
        for (int i = 0; i < points.size(); ++i)
        {
            auto &v = points[i];
            if (v[0] == x || v[1] == y)
            {
                int manDist = abs(v[0] - x) + abs(v[1] - y);
                if (dist < 0 || manDist < dist)
                {
                    ind = i;
                    dist = manDist;
                }
            }
        }

        return ind;
    }
};