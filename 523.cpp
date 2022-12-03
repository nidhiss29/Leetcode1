class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();

        unordered_map<int, int> mpp;

        // Why to insert <0,-1> for the hashmap

        // <0,-1> can allow it to return true when the runningSum%k=0,

        // for example [1,2,3] is input and k=6
        // then the remainders are [ 1,3,0] i.e runningSum = runningSum%k
        // now 1+2+3=6 which is actually a multiple of 6 and hence 0 should be stored in the hashmap

        // ok - but why -1?
        //-1 is good for storing for 0 because - it will remove the case where we consider only the first element which alone may be a multiple as 0-(-1) is not greater than 1

        // In addition, it also avoids the first element of the array is the multiple of k, since 0-(-1)=1 is not greater than 1.
        mpp[0] = -1;

        // Initialsize sum
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            int remainder = sum % k;

            // check if the runningsum already exists in the hashmap
            if (mpp.find(remainder) != mpp.end())
            {

                // if it exists, then the current location minus the previous location must be greater than1
                if (i - mpp[remainder] >= 2)
                {
                    return true;
                }
            }
            else
            {
                // otherwise if the current runningSum doesn't exist in the hashmap, then store it as it maybe used later on
                mpp[remainder] = i;
            }
        }
        return false;
    }
};