class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        //trivial but O(n)
  /*      vector<int> answer;
        for(int i =0;i<nums.size();i++){
            answer.push_back(nums[i]*nums[i]);
        }
        int n = answer.size();
        sort(answer.begin(),answer.end());
        return answer;   */
        
        
        //approach either use multiply -1 or abs() so get all +ve val sort and then sqauare but o(n^2)
        //another approach  (double pointer)
        //USE ptr from array start and end from 0 to n-1 compare largest and put rather than small as -4 and 3 will cause issue and extra comparisons would be needed
        int n = nums.size();
        int last = n-1;
        int start = 0;
        int index = n-1;
        vector <int>answ(n);
        
        while(start<=last){
            
            int val1 = nums[start]*nums[start];
            int val2 = nums[last]*nums[last];
            
            if(val1 > val2){
                answ[index] = val1;
                start++;
            }
            else{
                answ[index] = val2;
                last--;
            }
            index -- ;
        }
       return answ;
    }
};