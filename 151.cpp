class Solution
{
public:
    string reverseWords(string s)
    {
        if (s.empty())
            return "";

        istringstream ss(s);
        string reversed = "";
        while (ss)
        {
            string word;
            ss >> word;
            reversed = " " + word + reversed;
        }
        return reversed.substr(2, reversed.length());
    }
};