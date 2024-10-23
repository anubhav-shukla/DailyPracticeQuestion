class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        queue<TreeNode*> que;
        que.push(root);
        vector<int> levelSum;

        while (!que.empty()) {
            int currLevelSum = 0;
            int n = que.size();
            while (n--) {
                TreeNode* curr = que.front();
                que.pop();
                currLevelSum += curr->val;
                if (curr->left) {
                    que.push(curr->left);
                }
                if (curr->right) {
                    que.push(curr->right);
                }
            }
            levelSum.push_back(currLevelSum);
        }
        cout<<levelSum.size()<<endl;
        que.push(root);
        root -> val = 0;
        int i = 1;
        while (!que.empty()) {
            int n = que.size();
            while (n--) {
                TreeNode* curr = que.front();
                que.pop();
                int siblingSum = curr -> left != NULL ? curr -> left -> val : 0;
                siblingSum += curr -> right != NULL ? curr -> right -> val : 0;
                if(curr -> left){
                    curr -> left -> val = levelSum[i] - siblingSum;
                    que.push(curr -> left);
                }
                if(curr -> right){
                    curr -> right -> val = levelSum[i] - siblingSum;
                    que.push(curr -> right);
                }
            }
            i++;
        }
        return root;
    }
};