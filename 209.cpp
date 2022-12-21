class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {

        int n = nums.size();

        // minimal length
        int len = INT_MAX;

        // left and right pointer and subarray sum
        int left = 0;
        int right = 0;
        int sum = 0;

        // loop until right < n
        while (right < n)
        {
            // get current subarray sum
            sum += nums[right];

            // sum >= target then move left pointer until sum >= target and update length
            while (sum >= target)
            {
                len = min(len, right - left + 1);
                sum -= nums[left];
                left++;
            }

            right++;
        }

        // return length if not equal INT_MAX
        return len == INT_MAX ? 0 : len;
    }
};