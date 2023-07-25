
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



vector<int> findSpiral(Node *root)
{
    //Your code here
    vector<int> v;
    queue <Node*> pq;
    pq.push(root);
    int l_evel = 0;
    while(!pq.empty())
    {
        int size = pq.size();
        vector<int> v_v;
        for(int i = 0; i < size; i++)
        {
            Node * node = pq.front();
            pq.pop();
            v_v.push_back(node -> data);
            if(node -> left)
            {
                pq.push(node -> left);
            }
            if(node -> right)
            {
                pq.push(node -> right);
            }
        }
        if(l_evel % 2 == 0)
        {
            reverse(v_v.begin(), v_v.end());
        }
        // vector<int>
        for(auto ii : v_v)
        {
            v.push_back(ii);
        }
        l_evel++;
        
    }
    return v;
}
