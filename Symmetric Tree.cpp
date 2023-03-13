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
    bool isPalindrome(vector<int> &level) {
        int len = size(level);
        for(int i = 0, j = len-1; i < len/2; i++, j--) {
            if(level[i] != level[j]) return false;
        }
        return true;
    }
    bool traverseLevelWise(TreeNode *root) {
        TreeNode* dummyNode = new TreeNode(-101);
        queue<TreeNode*> myQueue;
        myQueue.push(root);
        while(!myQueue.empty()) {
            int len = myQueue.size();
            vector<int> level{};
            while(len--) {
                TreeNode* currNode = myQueue.front(); myQueue.pop();
                level.push_back(currNode->val);
                if(currNode != dummyNode) {
                    if(currNode->left)
                        myQueue.push(currNode->left);
                    else 
                        myQueue.push(dummyNode);
                    if(currNode->right) 
                        myQueue.push(currNode->right);
                    else 
                        myQueue.push(dummyNode);
                }
            }
            // for(auto &x: level) cout<< x<< " ";
            // cout<< endl;
            if(!isPalindrome(level)) return false;
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        return traverseLevelWise(root);
    }
};