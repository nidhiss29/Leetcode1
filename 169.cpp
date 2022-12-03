class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //floor of n/2 times
         //brute
        
  /*     //map implementation   O(N)
        int n = nums.size();
        int val = floor(n/2);
        unordered_map<int, int> map;
 
    for (int i = 0; i < n; i++)
        map[nums[i]]++;
            
       for(auto x:map){
          if(x.second > val)
              return x.first;
       }
        return -1;    */
        
        
        //NAIIVE not linear 
        //use two loops 1 to point at an elemnt and other to check its occurence in array if found mark visited in visit array to keep track of duplicacy
/*        int n = nums.size();   //O(N^2)
        int val = floor(n/2);
        vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency  
        
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j]) {
                visited[j] = true;
                count++;
            }
        }
       if (count > val)   //at end of every occurence check
           return nums[i];
        else
            count =0;
    }
        return -1;     */
        
        
        //Moore’s Voting Algorithm
        int cnt =0;
        int ele=0;
        
        for(int num:nums){
        if(cnt ==0){
            ele = num;
        }
        if(ele== num)
            cnt+=1;
        else
            cnt-=1;
        }
        return ele;
    }
};