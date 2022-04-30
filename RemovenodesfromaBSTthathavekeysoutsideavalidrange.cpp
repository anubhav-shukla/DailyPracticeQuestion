#include <iostream>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
// Function to perform inorder traversal on the tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
 
// Recursive function to insert a key into a BST
Node* insert(Node* root, int key)
{
    // if the root is null, create a new node and return it
    if (root == nullptr) {
        return new Node(key);
    }
 
    // if the given key is less than the root node, recur for the left subtree
    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    // if the given key is more than the root node, recur for the right subtree
    else {
        root->right = insert(root->right, key);
    }
 
    return root;
}
 
// Function to truncate the BST and remove nodes having keys
// outside the valid range
Node* truncate(Node* root, int low, int high)
{
    // base case
    if (root == nullptr) {
        return root;
    }
 
    // recursively truncate the left and right subtree first
    root->left = truncate(root->left, low, high);
    root->right = truncate(root->right, low, high);
 
    Node* curr = root;
 
    // if the root's key is smaller than the minimum allowed, delete it
    if (root->data < low)
    {
        root = root->right;
        delete curr;
    }
    // if the root's key is larger than the maximum allowed, delete it
    else if (root->data > high)
    {
        root = root->left;
        delete curr;
    }
 
    return root;
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    /* Construct the following tree
               15
             /    \
            /      \
           10       20
          / \      /  \
         /   \    /    \
        8    12 16     25
    */
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // the valid range is 9 to 12
    root = truncate(root, 9, 12);
    inorder(root);
 
    return 0;
}
