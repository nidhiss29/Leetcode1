class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         vector<int> count(26);
        
        for (const auto & item : tasks)
        {
            ++count[item - 'A'];
        }
        
        const int max_count = *max_element(count.begin(), count.end());
        
        int ans = (max_count - 1) * (n + 1);
        
        ans += count_if(count.begin(), count.end(), [& max_count] (const int & c) { return c == max_count; });
        
        ans = max(ans, (int)tasks.size());
        
        return ans;
    }
};

//https://leetcode.com/problems/task-scheduler/discuss/761428/C%2B%2B-Greedy