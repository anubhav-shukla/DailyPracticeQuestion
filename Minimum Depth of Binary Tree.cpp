class Solution {
public:
    int minDepth(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        int depth = 1;
        int size = 0;
        TreeNode* removed;
        
        while (!queue.empty()) {
            size = queue.size();
            for (int i = 0; i < size; i++) {
                removed = queue.front();
                queue.pop();
                if (removed == nullptr) continue;
                if (removed->left == nullptr && removed->right == nullptr)
                    return depth;
                queue.push(removed->left);
                queue.push(removed->right);
            }
            depth++;
        }
        
        return 0;
    }
};