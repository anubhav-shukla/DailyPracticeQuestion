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
    int sumNumbers(TreeNode* root) {
        if (root == NULL)
            return 0;
        int ret = 0;
        stack<pair<TreeNode*, int>> s;
        s.push({root, 0});
        while(!s.empty()) {
            auto it = s.top();
            s.pop();
            TreeNode* curr = it.first;
            int curr_sum = it.second;
            curr_sum = curr_sum * 10 + curr->val;
            // 如果是叶子节点
            if (curr->left == NULL && curr->right == NULL) {
                ret += curr_sum;
            }
            if (curr->right != NULL) {
                s.push({curr->right, curr_sum});
            }
            if (curr->left != NULL) {
                s.push({curr->left, curr_sum});
            }
        }
        return ret;
    }
};
