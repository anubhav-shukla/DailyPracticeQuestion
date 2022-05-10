#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
 
// Data structure to store a binary tree node
struct Node
{
    int data;
    Node* left, *right;
 
    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
 
// Recursive function to calculate the size of the binary tree
int size(Node* root)
{
    // base case
    if (root == nullptr) {
        return 0;
    }
 
    return size(root->left) + 1 + size(root->right);
}
 
// Traverse the tree in a preorder fashion and update the ancestors of
// all nodes in the boolean ancestor matrix
void constructAncestorMatrix(Node* root, unordered_set<Node*> &ancestors,
                vector<vector<bool>> &ancestorMatrix)
{
    // base case
    if (root == nullptr) {
        return;
    }
 
    // update all ancestors of the current node
    for (Node* node: ancestors) {
        ancestorMatrix[node->data][root->data] = true;
    }
 
    // add the current node to the set of ancestors
    ancestors.insert(root);
 
    // recur for the left and right subtree
    constructAncestorMatrix(root->left, ancestors, ancestorMatrix);
    constructAncestorMatrix(root->right, ancestors, ancestorMatrix);
 
    // remove the current node from the set of ancestors since all
    // descendants of the current node are already processed
    ancestors.erase(root);
}
 
// Function to construct an ancestor matrix from a given binary tree
vector<vector<bool>> constructAncestorMatrix(Node* root)
{
    // calculate the size of the binary tree
    int n = size(root);
 
    // create an ancestor matrix of size `n × n`, initialized by false
    vector<vector<bool>> ancestorMatrix(n, vector<bool>(n));
 
    // stores ancestors of a node
    unordered_set<Node*> ancestors;
 
    // construct the ancestor matrix
    constructAncestorMatrix(root, ancestors, ancestorMatrix);
 
    return ancestorMatrix;
}
 
int main()
{
    /* Construct the following tree
             4
           /   \
          3     1
         / \     \
        2   0     5
    */
 
    Node* root = new Node(4);
    root->left = new Node(3);
    root->right = new Node(1);
    root->left->left = new Node(2);
    root->left->right = new Node(0);
    root->right->right = new Node(5);
 
    // construct the ancestor matrix
    vector<vector<bool>> ancestorMatrix = constructAncestorMatrix(root);
 
    // print the ancestor matrix
    for (auto const &row: ancestorMatrix)
    {
        for (auto val: row) {
            cout << val << " ";
        }
        cout << endl;
    }
 
    return 0;
}
