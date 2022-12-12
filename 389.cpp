class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int table[26] = {0};

        for (auto ch : s)
            table[ch - 'a']--;
        for (auto ch : t)
            table[ch - 'a']++;

        for (int i = 0; i != 26; i++)
            if (table[i])
                return i + 'a';

        return ' ';
    }
};