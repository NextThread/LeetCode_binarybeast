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
  ListNode* reverse(ListNode* head)
    {
        if (head == NULL || head->next == NULL) return head;
        ListNode* rest = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return rest;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *a=reverse(l1),*b=reverse(l2);
        ListNode *ans= new ListNode(),*p=ans;
        int c=0;
        while(a and b){
            int s=c+a->val+b->val;
            if(s > 9){
                ans->next= new ListNode(s%10);
                c=1;
            }
            else{
                ans->next= new ListNode(s);
                c=0;
            }
            a=a->next;b=b->next;
            ans=ans->next;
        }
        while(a){
            int s=c+a->val;
            if(s > 9){
                ans->next= new ListNode(s%10);
                c=1;
            }
            else{
                ans->next= new ListNode(s);
                c=0;
            }
            a=a->next;
            ans=ans->next;
        }
        while(b){
            int s=c+b->val;
            if(s > 9){
                ans->next= new ListNode(s%10);
                c=1;
            }
            else{
                ans->next= new ListNode(s);
                c=0;
            }
            b=b->next;
            ans=ans->next;
        }
        if(c) ans->next= new ListNode(1);
        return reverse(p->next);
    }
};