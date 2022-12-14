class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> p_count(26, 0);
        for (char c : p)
            p_count[c - 'a']++;
        vector<int> s_count(26, 0);
        vector<int> result;
        for (int i = 0; i + 1 < p.size() && i < s.size(); ++i)
            s_count[s[i] - 'a']++;
        for (int i = 0; i + p.size() <= s.size(); ++i)
        {
            s_count[s[i + p.size() - 1] - 'a']++;
            if (p_count == s_count)
                result.push_back(i);
            s_count[s[i] - 'a']--;
        }
        return result;
    }
};