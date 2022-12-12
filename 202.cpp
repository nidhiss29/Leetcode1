class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 0)
            return false;

        unordered_map<int, bool> m;

        while (n > 1)
        {
            int num = n;
            int sum = 0;

            if (m.find(num) != m.end())
                return false;

            m[num] = true;
            while (num)
            {
                sum += ((num % 10) * (num % 10));
                num /= 10;
            }

            n = sum;
        }

        return (n == 1) ? true : false;
    }
};