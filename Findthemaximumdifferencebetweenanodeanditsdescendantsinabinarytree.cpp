#include <iostream>
#include <climits>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Helper function to find the maximum difference between a node and its
// descendants in a binary tree
int findMaxDifference(Node* root, int &diff)
{
    // base case: if the tree is empty, return infinity
    if (root == nullptr) {
        return INT_MAX;
    }
 
    // recur for the left and right subtree
    int left = findMaxDifference(root->left, diff);
    int right = findMaxDifference(root->right, diff);
 
    // find the maximum difference between the current node and its descendants
    int d = INT_MIN;
    if (min(left, right) != INT_MAX) {
        d = root->data - min(left, right);
    }
 
    // update the maximum difference found so far if required
    diff = max(diff, d);
 
    // For the difference to be maximum, the function should return
    // a minimum value among all subtree nodes
    return min(min(left, right), root->data);
}
 
// Find the maximum difference between a node and its descendants in a binary tree
int findMaxDifference(Node* root)
{
    int diff = INT_MIN;
    findMaxDifference(root, diff);
 
    return diff;
}
 
int main()
{
    /* Construct the following tree
              6
            /   \
           /     \
          3       8
                /   \
               /     \
              2       4
            /   \
           /     \
          1       7
    */
 
    Node* root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);
 
    cout << findMaxDifference(root);
 
    return 0;
}
