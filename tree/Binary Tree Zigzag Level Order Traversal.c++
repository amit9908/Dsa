
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;

        queue<TreeNode*> q;
        q.push(root);
        bool direction = true;

        while(!q.empty()){
            int width = q.size();
            vector<int> temp(width);
            for(int j=0 ; j<width ; j++){
                TreeNode* front = q.front();
                q.pop();
                int index = direction ? j : width - j -1;
                temp[index] = front->val;
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
                
            }
            direction =!direction;
            ans.push_back(temp);
        }
       
        return ans;
        
    }
};