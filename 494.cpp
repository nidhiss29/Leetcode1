class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int res = 0;
        recursive(nums, target, 0, 0, res);
        return res;
    }
    void recursive(vector<int> &nums, int target, int i, int tmp, int &res)
    {
        if (i >= nums.size())
        {
            if (target == tmp)
            {
                res++;
            }
            return;
        }
        recursive(nums, target, i + 1, tmp + nums[i], res);
        recursive(nums, target, i + 1, tmp + -nums[i], res);
    }
};