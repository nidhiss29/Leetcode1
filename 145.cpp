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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> stk;
        while (root || !stk.empty())
        {
            if (root)
            {
                stk.push(root);
                res.insert(res.begin(), root->val);
                root = root->right;
            }
            else
            {
                TreeNode *t = stk.top();
                stk.pop();
                root = t->left;
            }
        }

        return res;
    }
};