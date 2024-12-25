class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size() , maax = INT_MIN;  //len provides us the number of nodes available at a level
            while(len--) {   //this is where we traverse all nodes of same level
                auto temp = q.front();
                q.pop();
                maax = max(maax,temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(maax);
        }
        return ans;
    }
};