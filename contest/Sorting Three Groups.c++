class Solution {
public:
    int solve(int i,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i>=nums.size())
        return 0;
        
        if(dp[i][prev+1]!=-1)
        return dp[i][prev+1];

        int inc=0,exc=0;
        if(prev==-1 || nums[i]>=nums[prev]){
        inc=1+solve(i+1,i,nums,dp);
        exc=solve(i+1,prev,nums,dp);
        }
        else
        exc=solve(i+1,prev,nums,dp);

        return dp[i][prev+1]=max(inc,exc);        
    }
    
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        int ans=solve(0,-1,nums,dp);
        return n-ans;
    }
};