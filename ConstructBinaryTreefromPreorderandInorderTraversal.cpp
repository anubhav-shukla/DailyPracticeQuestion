#include<bits/stdc++.h>
using namespace std;
 
class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) { val = x; }
};
 
set<TreeNode*> s;
stack<TreeNode*> st;
TreeNode* buildTree(int preorder[], int inorder[],int n)
{
 
    TreeNode* root = NULL;
    for (int pre = 0, in = 0; pre < n;)
    {
 
        TreeNode* node = NULL;
        do
        {
            node = new TreeNode(preorder[pre]);
            if (root == NULL)
            {
                root = node;
            }
            if (st.size() > 0)
            {
                if (s.find(st.top()) != s.end())
                {
                    s.erase(st.top());
                    st.top()->right = node;
                    st.pop();
                }
                else
                {
                    st.top()->left = node;
                }
            }
            st.push(node);
        } while (preorder[pre++] != inorder[in] && pre < n);
 
        node = NULL;
        while (st.size() > 0 && in < n &&
                st.top()->val == inorder[in])
        {
            node = st.top();
            st.pop();
            in++;
        }
 
        if (node != NULL)
        {
            s.insert(node);
            st.push(node);
        }
    }
 
    return root;
}
 
void printInorder(TreeNode* node)
{
    if (node == NULL)
        return;
 
    printInorder(node->left);
 
    cout << node->val << " ";
 
    printInorder(node->right);
}
 
int main()
{
    int in[] = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    int pre[] = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    int len = sizeof(in)/sizeof(int);
 
    TreeNode *root = buildTree(pre, in, len);
 
    printInorder(root);
    return 0;
}