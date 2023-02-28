class Solution {
public:
    map<string,int>mp;
    string helper(TreeNode* root,vector<TreeNode*>&ans){
        if(root==NULL) return "$";
        string s=helper(root->left,ans)+","+helper(root->right,ans)+","+to_string(root->val);
        mp[s]++;
        if(mp[s]==2) ans.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>ans;
        helper(root,ans);
        return ans;
    }
};