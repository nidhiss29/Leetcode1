class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int first = 0, second = -1;
        int i = 1;
        int no = INT_MAX;
        for (int j = 0; j < nums.size() - 1; j++)
        {
            first = j;
            second = -1;
            if (nums[j] >= no)
                continue;
            for (i = j + 1; i < nums.size(); i++)
            {
                if (nums[i] < nums[first])
                {
                    continue;
                }
                if (second != -1 && nums[i] > nums[second])
                {
                    return true;
                }
                if (nums[i] > nums[first])
                {
                    second = i;
                    continue;
                }
            }
            no = min(no, nums[j]);
        }
        return false;
    }
};