/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void diff(TreeNode* root,vector<int> &n)
    {
        if(root==NULL)
        return;
        diff(root->left,n);
        n.push_back(root->val);
        diff(root->right,n);
    }
    int minDiffInBST(TreeNode* root) {
        vector<int>n;
        diff(root,n);
        int i=9999;
        for(int j=1;j<n.size();j++)
        {
            if(i>abs(n[j]-n[j-1]))
            i=abs(n[j]-n[j-1]);
        }
        return i;
    }
};