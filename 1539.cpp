class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {

        if (arr.size() == 0)
            return k;
        if (arr[0] > k)
            return k;
        k -= (arr[0] - 1);
        if (k == 0)
            return 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if ((arr[i] - arr[i - 1] - 1) >= k)
            {
                return arr[i - 1] + k;
            }
            k -= (arr[i] - arr[i - 1] - 1);
        }
        return arr[arr.size() - 1] + k;
    }
};