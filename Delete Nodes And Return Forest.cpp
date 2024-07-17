class Solution {

    private:
    
    vector<TreeNode*>arr;
    bool f(TreeNode* root,set<int>&del){
        
        if(root==nullptr)
            return false;

        if(f(root->left,del))
            root->left = nullptr;
        
        if(f(root->right,del))
            root->right = nullptr;
        
        if(del.count(root->val) > 0 ){

            if(root->left != nullptr)
                arr.push_back(root->left);
            
            if(root->right != nullptr)
                arr.push_back(root->right);

            // root = nullptr;

            return true;
        }
        return false;
    }

public:

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        set<int>del(to_delete.begin(),to_delete.end());
        

        if(!f(root,del))
            arr.push_back(root);
        
        return arr;

    }

};