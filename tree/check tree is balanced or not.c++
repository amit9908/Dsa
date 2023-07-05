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
// t.c 0(n^2)
class Solution {
public:
    int maxHeight(TreeNode* root){
        if(root == NULL) return 0;

        int h1 = maxHeight(root->left);
        int h2 = maxHeight(root->right);
        int ans = 1+max(h1,h2);

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;

        int leftHeight = maxHeight(root->left);
        int rightHeight = maxHeight(root->right);
        int diff = abs(leftHeight - rightHeight);
        bool ans1 = (diff<=1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if(ans1 && leftAns && rightAns){
            return true;
        }else{
            return false;
        }
        
    }
};
// t.c O(n)
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
    bool isbalanced = true;
    int maxHeight(TreeNode* root){
        if(root == NULL) return 0;

        int h1 = maxHeight(root->left);
        int h2 = maxHeight(root->right);
        if(isbalanced && abs(h1-h2) > 1){
            isbalanced = false;
            break;
        }
        int ans = 1+max(h1,h2);

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        maxHeight(root);
        return isbalanced;
    }
};