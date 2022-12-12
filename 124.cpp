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
    int traverse(TreeNode *root)
    {
        if (!root)
            return 0;
        int lsum = traverse(root->left);
        int rsum = traverse(root->right);

        ans = max(ans, lsum + rsum + root->val);
        auto sum = max(max(lsum, rsum), 0);
        return max(sum + root->val, 0);
    }
    int maxPathSum(TreeNode *root)
    {
        traverse(root);
        return ans;
    }

private:
    int ans = INT_MIN;
};