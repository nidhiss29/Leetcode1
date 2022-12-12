class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        int c = 0;

        int p1, p2;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
            {
                c++;
                if (c == 1)
                    p1 = i;
                else if (c == 2)
                    p2 = i;
                else if (c >= 3)
                    return 0;
            }
        }
        if (c == 1)
            return 0;
        if (c == 0)
            return 1;
        swap(s2[p1], s2[p2]);

        if (s1 == s2)
            return 1;
        return 0;
    }
};