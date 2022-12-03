class Solution
{
public:
    long long maximumSubsequenceCount(string t, string p)
    {
        long long sum = 0;
        int c = 0;
        for (int i = t.size(); i >= 0; i--)
        {
            if (t[i] == p[0])
            {
                sum += c;
            }
            if (t[i] == p[1])
            {
                c++;
            }
        }
        sum += c;
        long long sum1 = 0;
        int c1 = 1;
        for (int i = t.size(); i >= 0; i--)
        {
            if (t[i] == p[0])
            {
                sum1 += c1;
            }
            if (t[i] == p[1])
            {
                c1++;
            }
        }
        return max(sum, sum1);
    }
};