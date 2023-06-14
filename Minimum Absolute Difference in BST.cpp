class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        int prevVal = INT_MAX;
        int minDiff = INT_MAX;
        
        while (!st.empty() || curr != nullptr) {
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            if (prevVal != INT_MAX) {
                minDiff = min(minDiff, abs(curr->val - prevVal));
            }
            
            prevVal = curr->val;
            curr = curr->right;
        }
        
        return minDiff;
    }
};