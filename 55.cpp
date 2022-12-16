class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0, reach = 0;
        for (; i < n && i <= reach; i++)
            reach = max(reach, i + nums[i]);
        return reach + 1 >= n;
    }
};