class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // naive approach find element by for loop in whole and count for each occurence
        // sort and find if any elemnt exist adjacent to each other yes then return
        // if (arr[i] == arr[i + 1])

        // frequency array where store occurence of elemnt if 0 then do 1 else show  no
        /*        int n = nums.size();
            int freq[n+1]= {0};
                for(int i =0;i<n;i++){
                    if(freq[nums[i]]==0)
                        freq[nums[i]]+=1;
                        else{
                            return nums[i];
                        }
                }
                return 0;  */

        // another approach floyd's tortoise and hare method linked list cycle method

        int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);

        fast = nums[0];

        while (slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};