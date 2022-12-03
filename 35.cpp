class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        /*      int cnt=-1;          //o(n^2)

              for(int i =0;i<nums.size();i++){
                  if (nums[i] ==target)
                  {  return i;
                     cnt++;
                  } }

              if(cnt == -1){
              nums.push_back(target);
              sort(nums.begin(),nums.end());
                 for(int i=0;i<nums.size();i++){
                  if (nums[i] ==target)
                   return i; }
              }
              return 0;    */

        // o(log n ) complexity
        int low = 0;
        int high = nums.size() - 1;
        int mid;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return low; // atlast pointer vhi rukega jha humara value insert hona h dry run
    }
};