class Solution {
public:
    vector<TreeNode*> helper(int n){
        if(n  == 1){
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }
        
        vector<TreeNode*> ans;
        for(int i=1 ; i<n-1 ; i+=2){
            vector<TreeNode*> left = helper(i);
            vector<TreeNode*> right = helper(n-i-1);

            for(auto l1:left){
                for(auto l2:right){
                    TreeNode* head = new TreeNode(0);
                    head->left = l1;
                    head->right = l2;
                    ans.push_back(head);

                }
            }
        }
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
      return helper(n);  
    }
};