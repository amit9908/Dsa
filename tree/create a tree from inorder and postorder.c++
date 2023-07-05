


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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, unordered_map<int, int>& mt, int& postIndex, int start, int end) {
        if (postIndex < 0 || start > end) return NULL;

        int element = postorder[postIndex];
        TreeNode* root = new TreeNode(element);
        int findElement = mt[element];

        postIndex--;
        
        root->right = solve(postorder, inorder, mt, postIndex, findElement + 1, end);
        root->left = solve(postorder, inorder, mt, postIndex, start, findElement - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        unordered_map<int, int> mt;
        for (int i = 0; i < inorder.size(); i++) {
            mt[inorder[i]] = i;
        }
        int postIndex = postorder.size() - 1;
        TreeNode* ans = solve(postorder, inorder, mt, postIndex, 0, inorder.size() - 1);
        return ans;
    }
};
