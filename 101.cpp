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
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL)
            return true;
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode *left, TreeNode *right)
    {
        if (left == NULL)
        {
            if (right == NULL)
                return true;
            else
                return false;
        }
        else
        {
            if (right == NULL)
                return false;
            else
            {
                if (left->val == right->val)
                    return isSame(left->left, right->right) && isSame(left->right, right->left);
                else
                    return false;
            }
        }
    }
};