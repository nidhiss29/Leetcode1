class Solution
{
public:
    int maximum69Number(int num)
    {
        // brute to create an array of digits and changing each and checking highest
        // or just converting leftmost 6 to 9 either by string conv
        // another logic count 6 then num+3*pow(10,count) means conv 6 to 9 leftmost one

        string str = to_string(num);
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '6')
            {
                str[i] = '9';
                break;
            }
        }
        int sol = stoi(str);
        return sol;
    }
};