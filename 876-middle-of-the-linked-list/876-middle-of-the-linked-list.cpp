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
    ListNode* middleNode(ListNode* head) {
        
        // This is a perfect example of two pointer approach
        // we will be keeping two pointer as slow and fast
        // slow will get incremented by one step 
        // fast will get incremented by two at each step
        // at last when our fast stands at last, then our slow will be pointing to the mid
        // so we just return the slow pointer, which is currently pointing to the middle node
        if(!head) return NULL;
        if(!head->next) return head;
        ListNode* slow = head, *fast = head;
        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};