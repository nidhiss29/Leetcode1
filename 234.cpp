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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;
        ListNode *slow = head, *curr = head, *prev = nullptr;
        int n = 0;
        while (slow)
        {
            slow = slow->next;
            n++;
        }
        slow = head;
        for (int i = 0; i < n / 2; i++)
        {
            slow = slow->next;
        }
        while (curr != slow)
        {
            ListNode *forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        if (n % 2 == 1)
            slow = slow->next;
        while (slow)
        {
            if (slow->val != prev->val)
                return false;
            slow = slow->next;
            prev = prev->next;
        }
        return true;
    }
};