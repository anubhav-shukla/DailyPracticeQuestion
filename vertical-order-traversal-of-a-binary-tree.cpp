#include <bits/stdc++.h>
 
using namespace std;
 
// Structure for a binary tree node
struct Node {
    int key;
    Node *left, *right;
};
 
// A function to create a new node
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}
 
// The main function to print vertical
// order of a binary tree with given root
void printVerticalOrder(Node* root)
{
    // Base case
    if (!root) return;
 
    // Create a map and store vertical
    // order in map using
      // function getVerticalOrder()
    unordered_map<int, vector<int> > m;
    int hd = 0;
 
    // Create queue to do level order
    // traversal Every item of queue contains
    // node and horizontal distance
    queue<pair<Node*, int> > q;
    q.push({root, hd});
   
    // mn and mx contain the minimum and
      // maximum horizontal distance from root
    int mn=0,mx=0;
    while (q.size()>0) {
       
        // pop from queue front
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node* node = temp.first;
 
        // insert this node's data
          // in vector of hash
        m[hd].push_back(node->key);
 
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
       
        // Update mn and mx
        if(mn>hd)
          mn=hd;
        else if(mx<hd)
          mx=hd;
    }
 
    // run the loop from minimum to maximum
    // every horizontal distance hd
    for (int i=mn;i<=mx;i++)
    {
        vector<int> tmp=m[i];
        for(int j=0;j<tmp.size();j++)
          cout<<tmp[j]<<" ";
        cout<<endl;
      }
}
 
// Driver program to test above functions
int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}