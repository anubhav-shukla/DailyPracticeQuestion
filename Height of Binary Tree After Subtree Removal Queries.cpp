class Solution {
public:
    unordered_map<int, int> heightsAfterRemoval;

    int calculateHeights(TreeNode* node, int depth) {
        if (!node) return depth - 1;

        int leftSubtree = calculateHeights(node->left, depth + 1);
        int rightSubtree = calculateHeights(node->right, depth + 1);

        if (node->left) heightsAfterRemoval[node->left->val] = rightSubtree;
        if (node->right) heightsAfterRemoval[node->right->val] = leftSubtree;

        return max(leftSubtree, rightSubtree);
    }

    void updateHeights(TreeNode* node, int maxDepth) {
        if (!node) return;

        maxDepth = (maxDepth == -2 || heightsAfterRemoval[node->val] > maxDepth)
                   ? heightsAfterRemoval[node->val] : maxDepth;

        if (node->left && maxDepth > heightsAfterRemoval[node->left->val]) {
            heightsAfterRemoval[node->left->val] = maxDepth;
        }

        if (node->right && maxDepth > heightsAfterRemoval[node->right->val]) {
            heightsAfterRemoval[node->right->val] = maxDepth;
        }

        updateHeights(node->left, maxDepth);
        updateHeights(node->right, maxDepth);
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        calculateHeights(root, 0);
        updateHeights(root, -2);

        vector<int> result;
        for (int query : queries) {
            result.push_back(heightsAfterRemoval[query]);
        }
        return result;
    }
};