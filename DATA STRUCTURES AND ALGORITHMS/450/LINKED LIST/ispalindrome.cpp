// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

 // } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    //Function to check whether the list is palindrome.
    
    Node* reverse(Node *head){
        if(head==NULL or head->next==NULL)
            return head;
        Node *temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
    
    Node *middle(Node *head){
        if(head==NULL or head->next==NULL)
            return head;
        Node *slow=head,*fast=head->next;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node *mid = middle(head);
        Node *cur1 = head;
        Node *cur2 = reverse(mid);
        while(cur1!=NULL and cur2!=NULL){
            if(cur1->data != cur2->data)
                return false;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return true;
    }
};

// { Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}

  // } Driver Code Ends