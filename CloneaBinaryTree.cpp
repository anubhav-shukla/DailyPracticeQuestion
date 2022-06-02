#include <iostream>
using namespace std;
 
// A Binary Tree Node
class Node
{
public:
    int data;
    Node* left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->right = this->left = nullptr;
    }
};
 
// Function to print the inorder traversal on a given binary tree
void inorder(Node* root)
{
    if (root == nullptr) {
        return;
    }
 
    // recur for the left subtree
    inorder(root->left);
 
    // print the current node's data
    cout << root->data << " ";
 
    // recur for the right subtree
    inorder(root->right);
}
 
// Recursive function to clone a binary tree
Node* cloneBinaryTree(Node* root)
{
    // base case
    if (root == nullptr) {
        return nullptr;
    }
 
    // create a new node with the same data as the root node
    Node* root_copy = new Node(root->data);
 
    // clone the left and right subtree
    root_copy->left = cloneBinaryTree(root->left);
    root_copy->right = cloneBinaryTree(root->right);
 
    // return cloned root node
    return root_copy;
}
 
int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
 
    Node* clone = cloneBinaryTree(root);
 
    cout << "Inorder traversal of the cloned tree: ";
    inorder(clone);
 
    return 0;
}