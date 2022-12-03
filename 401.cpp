class Solution
{
public:
    int NumberOfBits(int n)
    {
        int hours = n / 60;
        int minutes = n % 60;
        int numsBit = 0;

        if (hours == 0)
            ;
        else if (hours == 1 || hours == 2 || hours == 4 || hours == 8)
            numsBit++;
        else if (hours == 7 || hours == 11)
            numsBit += 3;
        else
            numsBit += 2;

        numsBit += bitset<32>(minutes).count();
        return numsBit;
    }

    string GetTime(int n)
    {
        if (n == 0)
            return string("0:00");

        int hours = n / 60;
        int minutes = n % 60;
        string res = to_string(hours);
        res += ":";

        if (minutes < 10)
            res += '0';
        res += to_string(minutes);
        return res;
    }
    vector<string> readBinaryWatch(int num)
    {
        if (!num)
            return vector<string>{"0:00"};

        vector<string> res;
        for (int i = 0; i < 12 * 60; i++)
        {
            if (NumberOfBits(i) == num)
                res.push_back(GetTime(i));
        }

        return res;
    }
};