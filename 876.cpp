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
class Solution {
public:   //easiest approach find length an ddo len/2 and traverse till it and return temp
  ListNode* middleNode(ListNode* head) {
   /*     ListNode *temp = head;
        int length=0;
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        int half = length/2;
        temp=head;
        while(temp && half--)
        {
            temp=temp->next;
        }
        return temp;    */
    
    
    
    //another approach
   // 2pointer approach Keep 2 pointers, slow and fast. slow moves by one step whereas fast moves by 2 steps. By the time fast reaches the end of the LL, slow will point to the middle
    
    
    ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow= slow->next;
            fast= fast->next->next;
        }
        return slow;
    
    }
};