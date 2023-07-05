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
   void solve(vector<int>& inorder , TreeNode* root){
       if(!root) return ;

       solve(inorder , root->left);
       inorder.push_back(root->val);
       solve(inorder , root->right);
   }
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        solve(inorder , root);

        int s = 0;
        int e = inorder.size()-1;
        while(s < e){
            int sum  = inorder[s]+inorder[e];
            if(sum == k) return true;
            else if(sum > k) e--;
            else s++;
        }
        return false;
        
    }
};