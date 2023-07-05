class Solution {
public:

    void solve( vector<string>& ans  ,  string temp , TreeNode* root){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            temp += to_string(root->val);
            ans.push_back(temp);
            return ;
        }
        
        string oldtemp = temp ; 
        temp += to_string(root->val);
        temp.push_back('-');
        temp.push_back('>');
        solve(ans , temp ,root->left);
        solve(ans , temp , root->right);
        temp = oldtemp;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        solve(ans , temp  ,root);
        return ans;
    }
};
