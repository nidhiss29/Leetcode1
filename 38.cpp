class Solution
{
public:
    string countAndSay(int n)
    {
        string ans = "1";

        for (int i = 1; i < n; i++)
        {
            string curr = "";
            char prev = ans[0];
            int c = 1;
            for (int j = 1; j < ans.size(); j++)
            {
                if (prev == ans[j])
                    c++;
                else
                {
                    curr += to_string(c) + prev;
                    prev = ans[j];
                    c = 1;
                }
            }
            curr += to_string(c) + prev;
            ans = curr;
        }

        return ans;
    }
};