class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int p1 = 0, p2 = 0;
        for (int i : nums)
        {
            int temp = p2;
            p2 = max(p2, p1 + i);
            p1 = temp;
        }
        return p2;
    }
};