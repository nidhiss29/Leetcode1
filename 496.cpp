class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        int n1 = nums1.size();
        int n2 = nums2.size();

        for (int i = 0; i < n1; i++)
        {
            int index = 0;

            while (!(nums1[i] == nums2[index]) && index < n2)
            {
                index++;
            }

            while (!(nums1[i] < nums2[index]))
            {
                if (index == n2 - 1)
                {
                    nums1[i] = -1;
                    break;
                }
                else if (nums1[i] < nums2[index + 1])
                {
                    nums1[i] = nums2[index + 1];
                    break;
                }
                index++;
            }
        }
        return nums1;
    }
};