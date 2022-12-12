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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        traversal(res, root, 1);
        return res;
    }
    void traversal(vector<vector<int>> &res, TreeNode *root, int level)
    {
        if (!root)
        {
            return;
        }
        if (res.size() < level)
        {
            res.push_back(vector<int>());
        }
        res[level - 1].push_back(root->val);
        traversal(res, root->left, level + 1);
        traversal(res, root->right, level + 1);
    }
};