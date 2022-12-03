class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        /*      //naive O(n*log(n))+O(n) time
              int n = nums.size();
              set < int > set;
        for (int i = 0; i < n; i++) {
          set.insert(nums[i]);
        }
        int k = set.size();
        int j = 0;
        for (int x: set) {
          nums[j++] = x;
        }
        return k;    */

        // optimized 2 pointer

        int i = 0;
        int n = nums.size();
        for (int j = 1; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};