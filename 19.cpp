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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        int c = 0;

        while (fast != NULL)
        {
            if (c >= n)
            {
                prev = slow;
                slow = slow->next;
            }

            fast = fast->next;
            c++;
        }

        if (c == n)
            head = head->next;
        else
            prev->next = slow->next;
        return head;
    }
};