// https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/ source
class Solution {
     //first aproach recur1 using extra space O(n) space complexity
    
/*private: 
   void recurPermute(vector < int > & ds, vector < int > & nums, vector < vector < int >> & ans, int freq[]) {
      if (ds.size() == nums.size()) {
        ans.push_back(ds);
        return;
      }
      for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
          ds.push_back(nums[i]);
          freq[i] = 1;
          recurPermute(ds, nums, ans, freq);
          freq[i] = 0;
          ds.pop_back();
        }
      }
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
       
        vector<vector<int>>ans;
        vector<int> ds;
        
        int freq[ nums.size()]; //can't initialize with 0 during declaration so use forloop to do so
        for(int i =0;i< nums.size();i++) freq[i]=0;
         recurPermute(ds, nums, ans, freq);
        return ans;   
         */
    
    //second recursive approach
private:
    void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {
      if (index == nums.size()) {
        ans.push_back(nums);
        return;
      }
      for (int i = index; i < nums.size(); i++) {
        swap(nums[index], nums[i]);
        recurPermute(index + 1, nums, ans);
        swap(nums[index], nums[i]);
      }
    }
    
public:
     vector<vector<int>> permute(vector<int>& nums) {
       vector < vector < int >> ans;
      recurPermute(0, nums, ans);
      return ans;  
        
    }
    
};  