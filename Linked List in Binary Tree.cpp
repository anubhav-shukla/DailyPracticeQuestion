class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        bool left = false;
        bool right = false;
        if (head->val == root->val) {
            left = solve(head->next, root->left);
            right = solve(head->next, root->right);
        }
        return left || right;
    }
    bool match(ListNode* head, TreeNode* root) {
        if (!root)
            return false;
        bool rootpath = solve(head, root);
        bool leftpath = match(head, root->left);
        bool rightpath = match(head, root->right);
        return leftpath || rightpath || rootpath;
    }
    bool isSubPath(ListNode* head, TreeNode* root) { return match(head, root); }
};