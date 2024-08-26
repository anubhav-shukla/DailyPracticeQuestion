class Solution {
    void traversal(Node* root,vector<int>& ans){
        if(root == nullptr) return;
        for(Node* it: root->children){
            traversal(it,ans);
        }
        ans.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        vector<int>ans;
        traversal(root,ans);
        return ans;
    }
};