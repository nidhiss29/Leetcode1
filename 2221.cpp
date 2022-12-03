class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {

        if (nums.size() == 1)
            return nums[0];

        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i == (n - 1))
            {
                n = nums.size();
            }
            else
            {
                nums.push_back((nums[i] + nums[i + 1]) % 10);
            }
        }

        return nums[nums.size() - 1];
    }
};
