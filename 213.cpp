class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int a1 = 0, a2 = nums[0], b1 = 0, b2 = 0;
        for (int i = 1; i < nums.size() - 1; ++i)
            a1 = exchange(a2, max(a1 + nums[i], a2)), b1 = exchange(b2, max(b1 + nums[i], b2));
        b2 = max(b1 + nums.back(), b2);
        return max(a2, b2);
    }
};