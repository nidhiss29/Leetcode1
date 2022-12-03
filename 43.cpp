class Solution
{
public:
    string multiply(string num1, string num2)
    {
        /*  int num_1 = stoi(num1);   //small length
          int num_2 = stoi(num2);

          return to_string(num_1*num_2); */

        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        int i, j;
        vector<int> num(num1.size() + num2.size(), 0);
        for (i = num1.size() - 1; i >= 0; i--)
        {
            for (j = num2.size() - 1; j >= 0; j--)
            {
                num[i + j + 1] += (num1[i] - 48) * (num2[j] - 48);
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }
        i = 0;
        while (i < num.size() && num[i] == 0)
        {
            i++;
        }

        string res = "";
        while (i < num.size())
        {
            res.push_back(num[i] + '0');
            i++;
        }
        return res;
    }
};