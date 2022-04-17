#include <iostream>
#include <unordered_set>
using namespace std;
 
// Data structure to store a BST node
struct Node
{
    int data;
    Node* left = nullptr, *right = nullptr;
 
    Node() {}
    Node(int data): data(data) {}
};
 
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
 
// Function to find a pair with a given sum in a BST
bool findPair(Node* root, int target, auto &set)
{
    // base case
    if (root == nullptr) {
        return false;
    }
 
    // return true if pair is found in the left subtree; otherwise, continue
    // processing the node
    if (findPair(root->left, target, set)) {
        return true;
    }
 
    // if a pair is formed with the current node, print the pair and return true
    if (set.find(target - root->data) != set.end())
    {
        cout << "Pair found (" << target - root->data << ", " << root->data << ")";
        return true;
    }
 
    // insert the current node's value into the set
    else {
        set.insert(root->data);
    }
 
    // search in the right subtree
    return findPair(root->right, target, set);
}
 
int main()
{
    int keys[] = { 15, 10, 20, 8, 12, 16, 25 };
 
    Node* root = nullptr;
    for (int key: keys) {
        root = insert(root, key);
    }
 
    // find pair with the given sum
    int target = 28;
 
    // create an empty set
    unordered_set<int> set;
 
    if (!findPair(root, target, set)) {
        cout << "Pair does not exist";
    }
 
    return 0;
}