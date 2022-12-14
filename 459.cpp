class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        if (s.size() <= 1)
            return false;
        bool exist = false;
        int len = s.size();
        for (int i = 1; i <= len / 2; i++)
        {
            for (int j = 0; j <= len - 2 * i && !(s.size() % i); j = j + i)
            {
                string substr1 = s.substr(j, i);
                string substr2 = s.substr(j + i, i);
                if (substr1 == substr2)
                {
                    exist = true;
                }
                else
                {
                    exist = false;
                    break;
                }
            }
            if (exist)
            {
                return exist;
            }
        }
        return exist;
    }
};