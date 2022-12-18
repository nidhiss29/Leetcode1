class Solution {
public:
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<pair<int,int>> st;
    int n = temperatures.size();
    vector<int>ans(n);
    
    for(int i = n-1, d = 0; i >= 0; i--, d = 0){
      for(;!st.empty() && temperatures[i] >= st.top().first; st.pop()) d += st.top().second;
      
      if(st.empty()) st.push({temperatures[i] , ans[i] = 0});
      else st.push({temperatures[i] , ans[i] = ++d});   
    }
    
    return ans;
  }
};