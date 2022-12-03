class Solution
{
public:
    string removeDuplicates(string s)
    {
        string res;
        res.push_back(s[0]);
        for (int itr = 1; itr < s.size(); itr++)
        {
            if (res.size() && res.back() == s[itr])
                res.pop_back();
            else
                res.push_back(s[itr]);
        }
        return res;
    }
};