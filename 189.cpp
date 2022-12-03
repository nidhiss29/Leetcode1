class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        if (nums.size() <= 1)
            return;
        if (k >= nums.size())
            k = k % nums.size();
        std::rotate(nums.begin(), nums.begin() + (nums.size() - k), nums.end());
        return;
    }
};