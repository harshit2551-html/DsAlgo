// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;


// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
// you are required to complete this function
// function should return the size of the 
// Largest Independent set in the tree


//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

int solve(Node *root){
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    int a = root->left==NULL ? 0 : solve(root->left->left);
    int b = root->left==NULL ? 0 : solve(root->left->right);
    int c = root->right==NULL ? 0 : solve(root->right->left);
    int d = root->right==NULL ? 0 : solve(root->right->right);
    return max(1+a+b+c+d,solve(root->left)+solve(root->right));
}

int LISS(Node *root)
{
    //Code here
    return solve(root);
}


// { Driver Code Starts
int main()
{
  int t;
  scanf("%d\n", &t);
  while (t--)
  {
    string treeString;
	getline(cin,treeString);
	Node* root = buildTree(treeString);
    cout<<LISS(root)<<endl;
  }
  return 0;
}
  // } Driver Code Endssss