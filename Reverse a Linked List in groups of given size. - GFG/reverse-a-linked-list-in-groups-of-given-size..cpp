//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
   pair<node*,node*> help(node* head,int i,int k)
    {
        //base case
        if(head->next==NULL or i==1)
        {
            return {head,head->next};
        }
        
        //recursive calls
        //small calculation
        pair<node*,node*> temp=help(head->next,i-1,k);
        head->next->next=head;
        
        if(i==k)
        {
            head->next=temp.second;
        }
        
        return temp;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        node* h1=head;
        node* pre=NULL;
        bool flag=0;
        while(h1)
        {
            pair<node*,node*> p=help(h1,k,k);
            if(!flag)
            {
                pre=h1;
                head=p.first;
                flag=1;
            }
            else
            {
                pre->next=p.first;
                pre=h1;
            }
            h1=p.second;
        }
        return head;
        
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends