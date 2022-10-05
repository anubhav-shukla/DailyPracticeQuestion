#include <bits/stdc++.h>
 
using namespace std;
 
// Class of TreeNode
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
  // Constructor
    TreeNode(int v)
    {
        val = v;
        left = right = NULL;
    }
};
 
// Function to add one row to a
// binary tree
TreeNode *addOneRow(TreeNode *root, int K, int L)
{
    // If L is 1
    if (L == 1) {
 
        // Store the node having
        // the value K
        TreeNode *t = new TreeNode(K);
 
        // Join node t with the
        // root node
        t->left = root;
        return t;
    }
 
    // Stores the current Level
    int currLevel = 1;
 
    // For performing BFS traversal
    queue<TreeNode*> Q;
 
    // Add root node to Queue Q
    Q.push(root);
 
    // Traversal while currLevel
    // is less than L - 1
    while (Q.size() > 0 && currLevel < L - 1)
    {
 
        // Stores the count of the
        // total nodes at the
        // currLevel
        int len = Q.size();
 
        // Iterate while len
        // is greater than 0
        while (len > 0)
        {
 
            // Pop the front
            // element of Q
            TreeNode *node = Q.front();
            Q.pop();
 
            // If node.left is
            // not NULL
            if (node->left != NULL)
                Q.push(node->left);
 
            // If node.right is
            // not NULL
            if (node->right != NULL)
                Q.push(node->right);
 
            // Decrement len by 1
            len--;
        }
 
        // Increment currLevel by 1
        currLevel++;
    }
 
    // Iterate while Q is
    // non empty()
    while (Q.size() > 0)
    {
 
        // Stores the front node
        // of the Q queue
        TreeNode *temp = Q.front();
        Q.pop();
 
        // Stores its left sub-tree
        TreeNode *temp1 = temp->left;
 
        // Create a new Node with
        // value K and assign to
        // temp.left
        temp->left = new TreeNode(K);
 
        // Assign temp1 to the
        // temp.left.left
        temp->left->left = temp1;
 
        // Store its right subtree
        TreeNode *temp2 = temp->right;
 
        // Create a new Node with
        // value K and assign to
        // temp.right
        temp->right = new TreeNode(K);
 
        // Assign temp2 to the
        // temp.right.right
        temp->right->right = temp2;
    }
 
    // Return the updated root
    return root;
}
 
// Function to print the tree in
// the level order traversal
void levelOrder(TreeNode *root)
{
    queue<TreeNode*> Q;
 
    if (root == NULL) {
        cout<<("Null")<<endl;
        return;
    }
 
    // Add root node to Q
    Q.push(root);
 
    while (Q.size() > 0) {
 
        // Stores the total nodes
        // at current level
        int len = Q.size();
 
        // Iterate while len
        // is greater than 0
        while (len > 0) {
 
            // Stores the front Node
            TreeNode *temp = Q.front();
            Q.pop();
 
            // Print the value of
            // the current node
            cout << temp->val << " ";
 
            // If reference to left
            // subtree is not NULL
            if (temp->left != NULL)
 
                // Add root of left
                // subtree to Q
                Q.push(temp->left);
 
            // If reference to right
            // subtree is not NULL
            if (temp->right != NULL)
 
                // Add root of right
                // subtree to Q
                Q.push(temp->right);
 
            // Decrement len by 1
            len--;
        }
 
        cout << endl;
    }
}
 
// Driver Code
int main()
{
   
    // Given Tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(6);
 
    int L = 2;
    int K = 1;
 
    levelOrder(addOneRow(root, K, L));
}
