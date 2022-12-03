class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int c = 0;
        for (int i = 0; i <= 30; i++)
            if ((1 << i & x) != ((1 << i) & y))
                c++;
        return c;
    }
};