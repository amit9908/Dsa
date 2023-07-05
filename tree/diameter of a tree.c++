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
    int diameterOfBinaryTree(TreeNode* root) {

        if(root ==  NULL) return 0;

        int left = diameterOfBinaryTree(root->left);
        int right =  diameterOfBinaryTree(root->right);
        int curr = height(root->left) + height(root->right);
        return max(curr,max(left,right));
       
    }


    int height(TreeNode* root){
        if(root == NULL) return 0;
        int h1 = height(root->left);
        int h2 = height(root->right);
        return 1+max(h1,h2);

    }
};

// t.c 0(n)
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
     int d = 0;
     int maxHeight(TreeNode* root){
         if(root == NULL) return 0;
         int lh = maxHeight(root->left);
         int rh = maxHeight(root->right);
         int curr = lh+rh;
         d = max(d,curr);
         return(1+max(lh, rh));
        }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        maxHeight(root);
        return d;
    }
};
