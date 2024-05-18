class Solution {
public:
    int moves = 0;
    
    int distributeCoins(TreeNode* root) {
        postOrderTraversal(root);
        return moves;
    }
    
    int postOrderTraversal(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int left = postOrderTraversal(node->left);
        int right = postOrderTraversal(node->right);
        
        moves += abs(left) + abs(right);
        return node->val - 1 + left + right;
    }
};