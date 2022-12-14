class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        size_t cnt[128] = {}, m_cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i)
        {
            m_cnt = max(m_cnt, ++cnt[s[i]]);
            if (i - j + 1 - m_cnt > k)
                --cnt[s[j++]];
        }
        return min(s.size(), k + m_cnt);
    }
};