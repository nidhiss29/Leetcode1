/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
    vector<long> sum;
    int dfs(TreeNode *r)
    {
        if (!r)
            return 0;
        sum.emplace_back(dfs(r->left) + dfs(r->right) + r->val);
        return sum.back();
    }

    int maxProduct(TreeNode *root)
    {
        long ans = 0, mod = 1e9 + 7;
        dfs(root);
        for (auto s : sum)
            ans = max(ans, (sum.back() - s) * s);
        return ans % mod;
    }
};