class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        int carry = 0;
        int len = std::max(num1.length(), num2.length());
        int digit1 = 0, digit2 = 0;
        int base = '0';

        if (num1.length() < num2.length())
            num1.swap(num2);

        for (int i = 0; i < len; i++)
        {
            digit1 = num1[num1.length() - 1 - i] - base; // from character to int

            if (i < num2.length())
                digit2 = num2[num2.length() - 1 - i] - base; // from character to int

            num1[len - 1 - i] = static_cast<char>(((digit1 + digit2 + carry) % 10) + base);

            if (digit1 + digit2 + carry > 9)
                carry = 1;
            else
                carry = 0;

            digit1 = 0;
            digit2 = 0;
        }

        return carry == 1 ? '1' + num1 : num1;
    }
};