class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle[0] == '\0')
            return 0;
        int h = haystack.length(), n = needle.length(), j = 0;
        for (int i = 0; i <= h - n; i++)
        {
            for (j = 0; j < n; j++)
                if (needle[j] != haystack[i + j])
                    break;
            if (j == n)
                return i;
        }
        return -1;
    }
};