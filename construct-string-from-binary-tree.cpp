#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left
   child and a pointer to right child */
struct Node {
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node */
Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
// Function to construct string from binary tree
void treeToString(Node* root, string& str)
{
    // bases case
    if (root == NULL)
        return;
 
    // push the root data as character
    str.push_back(root->data + '0');
 
    // if leaf node, then return
    if (!root->left && !root->right)
        return;
 
    // for left subtree
    str.push_back('(');
    treeToString(root->left, str);
    str.push_back(')');
 
    // only if right child is present to
    // avoid extra parenthesis
    if (root->right) {
        str.push_back('(');
        treeToString(root->right, str);
        str.push_back(')');
    }
}
 
// Driver Code
int main()
{
    /* Let us construct below tree
                1
               / \
              2   3
             / \   \
            4   5   6    */
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(6);
    string str = "";
    treeToString(root, str);
    cout << str;
}