class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> expected;
        
        for(int i =0;i<heights.size();i++){
            expected.push_back(heights[i]);
        }
        sort(expected.begin(),expected.end());
        
        int diff=0;
        for(int i =0; i<heights.size();i++){
            if(expected[i] != heights[i])
                diff++;
        }
       return diff; 
    }
};

//or declare as    vector<int> compareHeights(heights.begin(), heights.end()); directly copied