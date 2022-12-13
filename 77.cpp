class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> res;
        vector<int> cur;
        backTrack(res, cur, 1, n, k);
        return res;
    }
    void backTrack(vector<vector<int>> &res, vector<int> cur, int idx, int n, int k)
    {
        if (cur.size() == k)
        {
            res.push_back(cur);
            return;
        }
        for (int i = idx; i <= n; i++)
        {
            vector<int> c = cur;
            c.push_back(i);
            backTrack(res, c, i + 1, n, k);
        }
    }
};