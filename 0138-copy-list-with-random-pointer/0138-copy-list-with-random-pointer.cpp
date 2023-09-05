/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
         if(head==NULL)
            return NULL;
        
        // temporary (copied) head node
        Node* temp=head;
        
        // 1st Pass
        
        while(temp!=NULL)
        {
             // Cloned node with same val as head
            Node* newnode= new Node(temp->val);
            
            // Insert the cloned node next to the original node
            // If A->B->C is the original linked list,
            // Linked list after weaving cloned nodes would be
            // A->A'->B->B'->C->C'
            
            newnode->next=temp->next;
            temp->next=newnode;
            temp=newnode->next;
        }
        
        temp=head;
        
        // Link random pointers of the newly created nodes
        // and iterate through the newly created list and
        // use original node's random pointers
        
        // 2nd Pass
        
        while(temp!=NULL)
        {
            temp->next->random=(temp->random)?(temp->random->next):NULL;       
            temp=temp->next->next;
        }
        
         // Unweave the current linked list to get back the 
        // original linked list and the cloned one.
        
		// A->B->C
        Node* original=head;
        
        // A'->B'->C'
        Node* clone=head->next;
        
        // Result is used for returning
        Node* result=head->next;
        // 3rd Pass
        
        while(original!=NULL)
        {
            original->next=original->next->next;
            clone->next= (clone->next)?(clone->next->next):NULL;
            
            original=original->next;
            clone=clone->next;
        }
        
        return result;
    }
};