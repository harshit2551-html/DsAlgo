// { Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* inputList(int size)
{
    Node *head, *tail;
    int val;
    
    cin>>val;
    head = tail = new Node(val);
    
    while(--size)
    {
        cin>>val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
}

Node* findIntersection(Node* head1, Node* head2);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>> n >> m;
	    
	    Node* head1 = inputList(n);
	    Node* head2 = inputList(m);
	    
	    Node* result = findIntersection(head1, head2);
	    
	    printList(result);
	    cout<< endl;
	}
	return 0;
}
// } Driver Code Ends


/* The structure of the Linked list Node is as follows:

struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

*/

Node* findIntersection(Node* head1, Node* head2)
{
    // Your Code Here
    Node *ans1=NULL,*ans2=NULL,*temp1=head1,*temp2=head2;
    while(temp1!=NULL and temp2!=NULL){
        struct Node *cur=NULL;
        if(temp1->data < temp2->data){
            temp1 = temp1->next;
            continue;
        }
        else if(temp1->data > temp2->data){
            temp2 = temp2->next; 
            continue;
        }
        else{
            cur = new Node(temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if(ans1==NULL){
            ans1 = cur;
            ans2 = cur;
        }
        else{
            ans1->next = cur;
            ans1 = ans1->next;
        }
    }
    return ans2;
}
















