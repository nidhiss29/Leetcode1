class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        for (int i = 1, j = 0; i <= n; i++)
        {
            if (nums.at(j) == val)
            {
                nums.erase(nums.begin() + j);
            }
            else
            {
                j++;
            }
        }
        return nums.size();
    }
};