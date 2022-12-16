class Solution
{
public:
    string get_reduced_string(const string &str)
    {
        string temp = "";
        int x = str.size() - 1;
        int count = 0;
        for (int i = x; i >= 0; i--)
        {
            if (str[i] == '#')
            {
                count++;
            }
            else if (count > 0)
            {
                count--;
            }
            else
                temp += str[i];
        }
        return temp;
    };
    bool backspaceCompare(string s, string t)
    {
        return get_reduced_string(s) == get_reduced_string(t);
    }
};