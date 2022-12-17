class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int k)
    {
        vector<int> res;
        int i = k, j = A.size() - 1, carry = 0;
        while (i > 0 or j >= 0)
        {
            int num1 = 0, num2 = 0;
            if (j < A.size())
                num1 = A[j--];
            if (i > 0)
                num2 = i % 10;
            int sum = num1 + num2 + carry;
            res.push_back(sum % 10);
            carry = sum / 10;
            i /= 10;
        }
        if (carry)
            res.push_back(carry);
        reverse(res.begin(), res.end());
        return res;
    }
};