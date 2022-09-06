#include <iostream>
using namespace std;
 
class TreeNode {
 
public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
 
// Inorder function to print the tree
void inorderPrint(TreeNode* root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}
 
// Postorder traversal
TreeNode* TrimTree(TreeNode* root)
{
    if (!root)
        return nullptr;
 
    // Traverse from leaf to node
    root->left = TrimTree(root->left);
    root->right = TrimTree(root->right);
 
    // We only trim if the node's value is 0
    // and children are null
    if (root->data == 0 && root->left == nullptr
        && root->right == nullptr) {
 
        // We trim the subtree by returning nullptr
        return nullptr;
    }
 
    // Otherwise we leave the node the way it is
    return root;
}
 
// Driver code
int main()
{
    /*
           1
         /   \
       0      1
      / \    /  \
    0    0  0    1
    */
 
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(0);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(1);
 
    TreeNode* ReceivedRoot = TrimTree(root);
    cout << endl;
    inorderPrint(ReceivedRoot);
    /*
              1
                \
                  1
                    \
                     1
    */
}
