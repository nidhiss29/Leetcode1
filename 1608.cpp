class Solution {
public:
    int specialArray(vector<int>& nums) {
          int n = nums.size();
      sort(nums.begin(),nums.end());
      
      for(int i = 0 ; i < nums.size() ; i++,n--)
        if(nums[i] >= n && (i == 0 || nums[i - 1] < n )) return n;
      
      return -1;
    }
};