class Solution
{
public:
    int findMiddleIndex(vector<int> &nums)
    {
        int total = 0, sum = 0;
        for (auto no : nums)
        {
            total += no;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if ((sum - nums[i]) == (total - sum))
                return i;
        }
        return -1;
    }
};