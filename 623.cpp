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
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        TreeNode *dummy = new TreeNode(-1, root, nullptr);
        recursive(dummy, val, depth, 1);
        return dummy->left;
    }
    void recursive(TreeNode *root, int val, int depth, int curr)
    {
        if (!root)
        {
            return;
        }
        if (curr == depth)
        {
            TreeNode *newL = new TreeNode(val, root->left, nullptr);
            TreeNode *newR = new TreeNode(val, nullptr, root->right);
            root->left = newL, root->right = newR;
            return;
        }
        recursive(root->left, val, depth, curr + 1);
        recursive(root->right, val, depth, curr + 1);
    }
};