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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mt, int& preIndex, int start, int end) {
        if (preIndex >= preorder.size() || start > end) return NULL;

        int element = preorder[preIndex];
        TreeNode* root = new TreeNode(element);
        int findElement = mt[element];

        preIndex++;
        root->left = solve(preorder, inorder, mt, preIndex, start, findElement - 1);
        root->right = solve(preorder, inorder, mt, preIndex, findElement + 1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mt;
        for (int i = 0; i < inorder.size(); i++) {
            mt[inorder[i]] = i;
        }
        int preIndex = 0;
        TreeNode* ans = solve(preorder, inorder, mt, preIndex, 0, inorder.size() - 1);
        return ans;
    }
};
