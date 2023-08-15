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
    ListNode *partition(ListNode *head, int x) {
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *p1 = newHead;
        while (p1->next) 
        {    
            if((p1->next->val)<x)
                p1 = p1->next;
            else
                break;
        }
        ListNode *p2 = p1;
        
        ListNode *nextOne;
        while (p2->next) 
        {
            nextOne = p2->next;
            if (nextOne->val<x)
            {
                p2->next = nextOne->next;
                nextOne->next = p1->next;
                p1->next = nextOne;
                p1 = p1->next;
            }
            else
            {
                p2 = p2->next;
            }
        }
        return newHead->next;
    }
};