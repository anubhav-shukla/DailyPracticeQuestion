class Solution {
public:
    TreeNode*lca(TreeNode*root,int a,int b){
        if( root==nullptr || root->val==a || root->val==b )return root;
        TreeNode*left = lca( root->left,a,b );
        TreeNode*right = lca( root->right,a,b );
        if( left && right )return root;
        return (left)?left:right;
    }
    // TreeNode*lca(TreeNode*root,int a,int b){
    //     if( root==nullptr )return nullptr;
    //     if( root->val==a || root->val==b )return root;
    //     TreeNode*left = lca( root->left,a,b );
    //     TreeNode*right = lca( root->right,a,b );
    //     if( left==nullptr ){
    //         return right;
    //     }
    //     if( right==nullptr){
    //         return left;
    //     }else{
    //         return root;
    //     }
    // }
    bool find_value(TreeNode*root,int value,string& ans){
        if(root==nullptr)return false;
        if(root->val==value)return true;
        if(find_value(root->left,value,ans)){
            ans += 'L';
            return true;
        }
        if(find_value(root->right,value,ans)){
            ans += 'R';
            return true;
        }
        return false;
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        root = lca(root,startValue,destValue);
        string start="";
        string end="";
        find_value(root,startValue,start);
        find_value(root,destValue,end);
        for(char& c:start){
            c='U';
        }
        reverse(end.begin(),end.end());
        return start+end;
    }
};