class Solution {
public:
    int find(vector<vector<int>>& offers, int x){
        
        int l=0;
        
        int r=offers.size()-1;
        int ans=-1;
        
        while(l<=r){
            int mid=l+(r-l)/2;
            
            if(offers[mid][0]>x){
                ans=mid;
                r=mid-1;
            }
            else {
                l=mid+1;
            }
            
        }
        return ans;
        
    }
    int solve(int index,vector<vector<int>>& offers,vector<int > &dp){
        
        if(index>=offers.size()){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        int ans=find(offers,offers[index][1]);
        int acc=0;
        
        
        acc= offers[index][2]+solve(ans,offers,dp);    
        
        
        int don= solve(index+1,offers,dp);
        
        return dp[index]=max(acc,don);
    }
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
        
        int ans=0;
        vector<int > dp(offers.size(),-1);
        
        sort(offers.begin(),offers.end());
        
        return solve(0,offers,dp);
        
    }
};