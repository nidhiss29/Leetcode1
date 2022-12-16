class Solution {
public:
    int b_search(vector<int> &v, int l, int h, int target) {
        while(l <= h) {
            int m = l + (h - l)/2;
            
            if(target == v.at(m)) return m;
            else if(target > v.at(m)) l = m + 1;
            else h = m - 1;
        }
        return -1;
    }
    
    int pivot_index(const vector<int> &v) {
        int n = (int)v.size();
        int l = 0, h = n - 1;
        
        int pivot = -1;
        while(l <= h) {
            int m = l + (h - l) / 2;
            int left = (m + n - 1) % n, right = (m + 1) % n;
            
            if(v.at(l) <= v.at(h)) {
                pivot = l;
                break;
            } else if(v.at(m) <= v.at(left) && v.at(m) <= v.at(right)) {
                pivot = m;
                break;
            } else if(v.at(m) <= v.at(h)) {
                h = m - 1;
            } else if(v.at(m) >= v.at(l)) {
                l = m + 1;
            }
        }
        return pivot;
    }
    
    int search(vector<int>& nums, int target) {
        int pivot = pivot_index(nums);
        
        if(target >= nums.at(pivot) && target <= nums.back())
            return b_search(nums, pivot, (int)nums.size() - 1, target);
        return b_search(nums, 0, pivot-1, target);
    }
};