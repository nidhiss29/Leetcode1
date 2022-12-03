// https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // naive approach but time limit exceed O(n^3) basically subarray iterate from i to j nd check fr max sum out of it
        /*      vector < int > subarray;
            int max_sum = INT_MIN;
          int n = nums.size();
          if (n == 1) {
            return nums[0];
          }
          int i, j;
          for (i = 0; i <= n - 1; i++) {
            for (j = i; j <= n - 1; j++) {
              int sum = 0;
              for (int k = i; k <= j; k++)
                sum = sum + nums[k];
              if (sum > max_sum) {
                subarray.clear();
                max_sum = sum;
                subarray.push_back(i);
                subarray.push_back(j);

              }
            }
          }
          return max_sum;   */
        // Optimized Kadane's algo O(n) complexity
        int sum = 0;
        int maxim = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (sum > maxim)
                maxim = sum;
            if (sum < 0)
                sum = 0;
        }
        return maxim;
    }
};