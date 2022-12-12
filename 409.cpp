class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> m;
        int res = 0;
        bool center = false;
        for (char c : s)
            m[c]++;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            res += it->second;
            if (it->second % 2 == 1)
            {
                res -= 1;
                center = true;
            }
        }
        return center ? res + 1 : res;
    }
};