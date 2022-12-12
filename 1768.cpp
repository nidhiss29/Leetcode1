class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int n = word1.size();
        int n1 = word2.size();
        int mx = max(n, n1);

        string ans;
        for (int i = 0; i < mx; i++)
        {
            if (i < n)
                ans += word1[i];

            if (i < n1)
                ans += word2[i];
        }
        return ans;
    }
};