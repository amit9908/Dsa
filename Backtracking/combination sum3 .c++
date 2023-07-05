class Solution {
public:
    
    void solve(int k,int target,int currSum,int i,vector<int>&curr,vector<vector<int>>&ans){

        if(curr.size()==k && currSum == target){
            ans.push_back(curr);
            return;
        }
        if(currSum>target){
            return;
        }
        if(curr.size()>k) {
            return;
        }
        if(i==9){
            return;
        }

        //Accept 
        curr.push_back(i+1);
        currSum+=(i+1);
        solve(k,target,currSum,i+1,curr,ans);
        currSum-=(i+1);
        curr.pop_back();

        //Reject
        solve(k,target,currSum,i+1,curr,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>curr;
        vector<vector<int>>ans;
        solve(k,n,0,0,curr,ans);
        return ans;
    }
};