class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap({{0, 1}});
        int s = 0, res = 0;

        for (int num : nums)
        {
            s += num;
            res += umap[s - k];
            umap[s] += 1;
        }
        return res;
    }
};