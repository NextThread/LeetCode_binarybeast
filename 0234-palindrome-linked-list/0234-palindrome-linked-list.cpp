class Solution {
public:
    bool isPalindrome(ListNode* head) {
    //    1     2     2     1
    //   f,s    s    psf    s      f
      
        // ListNode *slow = head, *fast = head, *prev, *temp;
        // while (fast && fast->next)
        //     slow = slow->next, fast = fast->next->next;
        // prev = slow, slow = slow->next, prev->next = NULL;
        // while (slow)
        //     temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        // fast = head, slow = prev;
        // while (slow)
        //     if (fast->val != slow->val) return false;
        //     else fast = fast->next, slow = slow->next;
        // return true;
        
        //using stack
       //tc-> O(N)    &&   sc->O(N)
        
        ListNode* temp = head;
        stack<int> st;
        while(temp)
        {
            st.push(temp->val);
            temp = temp->next;
        }
        while(head)
        {
            if(st.top() != head->val) return false;
            st.pop();
            head = head->next;
        }
        return true;
    }
};