int inorderTraversal(TreeNode* root,int L, int R){
    int sum = 0;
    TreeNode *cur = root,*pre;
    while(cur!=nullptr){
        if(cur->left!=nullptr){
            pre = cur->left;
            while(pre->right!=nullptr && pre->right!=cur){
                pre = pre->right;
            }
            if(pre->right==nullptr){
                pre->right = cur;
                cur = cur->left;
            }else{
                if(cur->val>=L && cur->val<=R)
                    sum+=cur->val;
                pre->right = nullptr;
                cur = cur->right;
            }
        }else{
            if(cur->val>=L && cur->val<=R)
                    sum+=cur->val;
            cur = cur->right;
        }
    }
    return sum;
}
int rangeSumBST(TreeNode* root, int L, int R) {
    if(root==nullptr)
        return 0;
    return inorderTraversal(root,L,R);
}