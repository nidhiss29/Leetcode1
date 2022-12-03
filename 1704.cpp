class Solution
{
public:
    /* char c1 = s[i];
        char c2 = s[s.size()-i-1]; or directly check vowel nd increase */

    int numofvowels(string s, int start, int end)
    {
        int cnt = 0;
        for (int i = start; i < end; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
                cnt++;
        }
        return cnt;
    }

    bool halvesAreAlike(string s)
    {
        return numofvowels(s, 0, s.size() / 2) == numofvowels(s, s.size() / 2, s.size());
    }
};

// or checking each character with isvowel function and to islower for less comparisons