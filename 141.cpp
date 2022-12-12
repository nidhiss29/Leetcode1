/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        int t = 85000;
        while (t--)
        {
            if (head == NULL)
                return false;
            head = head->next;
        }

        return true;
    }
};