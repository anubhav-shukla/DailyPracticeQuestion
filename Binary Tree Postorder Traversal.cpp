class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root) return vector<int> ();
        vector<int> ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()) {
            TreeNode* tmp = s.top();s.pop();
            ans.push_back(tmp->val);
            if (tmp->left) {
                s.push(tmp->left);
            }
            if (tmp->right) {
                s.push(tmp->right);    
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};