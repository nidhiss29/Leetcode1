class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int carry = 0;
        for (int i = a.length() - 1, j = b.length() - 1; i >= 0 || j >= 0 || carry == 1; --i, --j)
        {
            int x = i < 0 ? 0 : a[i] - '0';
            int y = j < 0 ? 0 : b[j] - '0';
            res += to_string((x + y + carry) % 2);
            carry = (x + y + carry) / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};