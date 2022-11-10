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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 || l2 || carry) // till we have l1 or l2 or carry
        {
            if(l1) 
            {
              carry += l1->val;
              l1 = l1->next; 
            }
            if(l2) 
            {
              carry += l2->val;
              l2 = l2->next; 
            }
            curr->next = new ListNode(carry % 10); // if after adding we have something > 9
            curr = curr->next;
            carry /= 10;
        }
        return dummy->next;
    }
};