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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addByBit(l1, l2, 0);
    }

    ListNode *addByBit(ListNode *l1, ListNode *l2, int carry)
    {
        if (l1 == NULL)
            l1 = new ListNode(0);
        if (l2 == NULL)
            l2 = new ListNode(0);
        ListNode *l = new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry) / 10;
        if (l1->next != NULL || l2->next != NULL || carry == 1)
        {
            l->next = addByBit(l1->next, l2->next, carry);
        }
        return l;
    }
};