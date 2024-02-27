class Solution {
public:
    // Function to calculate the diameter and height of a subtree recursively
    pair<int, int> calculateDiameterAndHeight(TreeNode* root) {
        if (root == nullptr) {
            // Base case: Empty subtree has diameter and height 0
            return {0, 0};
        }

        // Get diameter and height information for left and right subtrees
        auto leftData = calculateDiameterAndHeight(root->left);
        auto rightData = calculateDiameterAndHeight(root->right);

        // Calculate current subtree's diameter:
        // - Maximum path passing through root
        // - Maximum diameter in left or right subtree
        int currentDiameter = max(leftData.second + rightData.second, 
                                  max(leftData.first, rightData.first));

        // Calculate current subtree's height (maximum path through root)
        int currentHeight = max(leftData.second, rightData.second) + 1;

        return {currentDiameter, currentHeight};
    }

    int diameterOfBinaryTree(TreeNode* root) {
        // The diameter of the entire tree is the maximum diameter found across subtrees
        return calculateDiameterAndHeight(root).first;
    }
};