if (s.size() == 0)
    return 0;
int index = s.find_first_not_of(' '), n = s.size(), sign = 1, num = 0;
if (index == string::npos)
    index = 0;
if (index == n)
    return 0;
if (s[index] == '+' || s[index] == '-')
{
    sign = s[index++] == '+' ? 1 : -1;
}

for (; index < s.size(); index++)
{
    if (!isdigit(s[index]))
    {
        return num;
    }
    int digit = sign * (s[index] - '0');
    if (sign == 1 && num > (INT_MAX - digit) / 10)
        return INT_MAX;
    if (sign == -1 && num < (INT_MIN - digit) / 10)
        return INT_MIN;
    num = num * 10 + digit;
}
return num;