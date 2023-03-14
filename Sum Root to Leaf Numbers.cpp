class Solution {
public:
    int sumNumbers(TreeNode* root, int sum=0) {
        int ret=0;
        sum=sum*10+root->val;
        if(!root->left && !root->right)
        {
            ret+=sum;
        }
        if(root->left) ret+=sumNumbers(root->left,sum);
        if(root->right) ret+=sumNumbers(root->right,sum);
        return ret;
    }
};