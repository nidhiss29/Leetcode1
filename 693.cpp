class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        bool prev = (n & 1) ? false : true;

        for (int i = n, pos = 0; i > 0; i /= 2, pos++)
        {
            bool curr = (n & (1 << pos));

            if (prev == curr)
                return false;
            prev = curr;
        }

        return true;
    }
};