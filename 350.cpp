class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        int f = 0;
        for (auto i = nums1.begin(); i != nums1.end();)
        {
            for (auto j = nums2.begin(); j != nums2.end();)
            {
                if (*i == *j)
                {
                    v.push_back(*i);
                    nums1.erase(i);
                    nums2.erase(j);
                    f = 1;
                    break;
                }
                j++;
            }
            if (f)
            {
                f = 0;
                continue;
            }
            i++;
        }
        return v;
    }
};