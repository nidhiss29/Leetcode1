/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool isinside(ListNode *listnode, TreeNode *treenode)
    {
        if (nullptr == treenode)
            return false;

        if (listnode->val == treenode->val)
        {
            if (nullptr == listnode->next)
                return true;
            else
            {
                if (isinside(listnode->next, treenode->left) || isinside(listnode->next, treenode->right))
                    return true;
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    bool isSubPath(ListNode *head, TreeNode *root)
    {

        if (nullptr == root)
            return false;
        if (isinside(head, root))
            return true;
        else
        {
            if (isSubPath(head, root->left) || isSubPath(head, root->right))
                return true;
            else
                return false;
        }
    }
};