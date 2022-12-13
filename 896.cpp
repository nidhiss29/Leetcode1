class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        vector<int> B = A;
        reverse(B.begin(), B.end());
        return is_sorted(A.begin(), A.end()) || is_sorted(B.begin(), B.end());
    }
};

/*   vector<int> increase = A;
        sort(increase.begin(), increase.end());

        vector<int> decrease = A;
        sort(decrease.begin(), decrease.end(), greater<int>());

        if (A == increase || A == decrease)
            return true;
        else
            return false;
*/