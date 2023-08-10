/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void fill_parent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent){
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) return;

        if(root->left != NULL) parent[root->left] = root;

        if(root->right != NULL) parent[root->right] = root;

        fill_parent(root->left, parent);

        fill_parent(root->right, parent);


    }


    void K_distance(unordered_map<TreeNode*, TreeNode*> &parent, TreeNode* t, int k, vector<int> &ans, unordered_map<TreeNode*, bool> &visited){
        if(t == NULL) return;

     
     
          visited[t] = 1;


         if(k == 0){
            ans.push_back(t->val);
            return;
         }

         if(t->left != NULL && visited[t->left] == 0) K_distance(parent, t->left, k-1, ans, visited);

         if(t->right != NULL && visited[t->right] == 0) K_distance(parent, t->right, k-1, ans, visited);

         if(parent.find(t) != parent.end() && visited[parent[t]] == 0) K_distance(parent, parent[t], k-1, ans, visited);


    }


    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;

        unordered_map<TreeNode*, bool> visited;

        fill_parent(root, parent);


        vector<int> ans;

        K_distance(parent, target, k, ans, visited);

         return ans;

    }
};