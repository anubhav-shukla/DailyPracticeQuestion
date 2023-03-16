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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder,int curoot,int l,int h){
        if(l==h) return new TreeNode(inorder[l]);
        
        if(l<h){
            auto itr = find (inorder.begin()+l, inorder.begin() + h, postorder[curoot]);
            while(*itr != postorder[curoot]){
                curoot = curoot -1;
                itr = find (inorder.begin()+l, inorder.begin() + h, postorder[curoot]);
            }
            int mid = distance(inorder.begin(),itr);
            TreeNode *node = new TreeNode(inorder[mid]);
            if(mid>0)
                node->left = solve(inorder,postorder,curoot-1,l,mid-1);
            if(mid<inorder.size()-1)
                node->right = solve(inorder,postorder,curoot-1,mid+1,h);

            return node;
        }
        return NULL;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int l=0,h=inorder.size()-1;
        int curoot = postorder.size()-1;

        return solve(inorder,postorder,curoot,l,h);
        
    }
};