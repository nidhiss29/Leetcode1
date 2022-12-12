class NumArray
{
public:
    vector<int> v;
    NumArray(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0)
            {
                v.push_back(nums[i]);
            }
            else
            {
                v.push_back(nums[i] + v[i - 1]);
            }
        }
    }

    int sumRange(int i, int j)
    {
        if (i == 0)
        {
            return v[j];
        }
        return v[j] - v[i - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */