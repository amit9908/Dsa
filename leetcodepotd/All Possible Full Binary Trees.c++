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


class Solution {
public:
    vector<TreeNode*> helper(int n ,vector<vector<TreeNode*>>& dp){
        if(n  == 1){
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }

        if(!dp[n].empty()) return dp[n];

        vector<TreeNode*> ans;
        for(int i=1 ; i<n-1 ; i+=2){
            vector<TreeNode*> left = helper(i,dp);
            vector<TreeNode*> right = helper(n-i-1,dp);

            for(auto l1:left){
                for(auto l2:right){
                    TreeNode* head = new TreeNode(0);
                    head->left = l1;
                    head->right = l2;
                    ans.push_back(head);
                }
            }
        }
        return dp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        vector<vector<TreeNode*>> dp(n + 1);

        if(n % 2 == 0) return ans;
        return helper(n, dp);
    }
};




class Solution {
public:
    unordered_map<int , vector<TreeNode*>> mp;
    vector<TreeNode*> helper(int n){
        if(n  == 1){
            TreeNode* temp = new TreeNode(0);
            return {temp};
        }

        if(mp.find(n) != mp.end()) return mp[n];

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
        return mp[n] = ans;
    }

    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;

        if(n % 2 == 0) return ans;
        return helper(n);
    }
};