class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        // map approach or by loop

        int n = nums.size();
        vector<int> answer;
        int val = floor(n / 3);
        unordered_map<int, int> map;

        for (int i = 0; i < n; i++)
            map[nums[i]]++;

        for (auto x : map)
        {
            if (x.second > val)
                answer.push_back(x.first);
        }
        return answer;

        // extended boyre's moore algo

        // https://takeuforward.org/data-structure/majority-elementsn-3-times-find-the-elements-that-appears-more-than-n-3-times-in-the-array/
    }
};