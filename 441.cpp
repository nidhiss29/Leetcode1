class Solution
{
public:
    int arrangeCoins(int n)
    {
        long long i = 0;
        for (i = 1; (i * (i + 1) / 2) <= n; i++)
            ;
        return i - 1;
    }
};