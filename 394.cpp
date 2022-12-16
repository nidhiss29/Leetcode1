class Solution
{
public:
    int extractInt(string &s, int &pos)
    {
        string strNum = "";
        while (s[pos] != '[')
        {
            strNum += s[pos++];
        }

        pos++;
        return stoi(strNum);
    }

    string decodeString(string &s, int &pos)
    {
        string res = "";

        while (pos < s.length() && s[pos] != ']')
        {
            if (s[pos] >= '1' && s[pos] <= '9')
            {
                int num = extractInt(s, pos);

                string t = decodeString(s, pos);
                for (int i = 0; i < num; i++)
                    res += t;
            }
            else
            {
                res += string(1, s[pos]);
                pos++;
            }
        }

        pos++;
        return res;
    }

    string decodeString(string s)
    {
        int pos = 0;
        return decodeString(s, pos);
    }
};