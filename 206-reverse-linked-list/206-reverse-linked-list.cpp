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
    ListNode* reverseList(ListNode* head) {
       // if (!head or !(head -> next)) {
       //      return head;
       //  }
       //  ListNode* node = reverseList(head -> next);
       //  head -> next -> next = head;
       //  head -> next = NULL;
       //  return node;   
        ListNode* prev = nullptr, *nextNode;
        while(head){
            nextNode = head->next;
            head -> next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
};