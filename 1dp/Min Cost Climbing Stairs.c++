class Solution {
public:
    int solve(int index , vector<int>& cost  ,vector<int>& dp){
        if(index == cost.size()-1  || index == cost.size()-2){
            return cost[index];
        }
        

        if(index>=cost.size()){
            return 0;
        }

        if(dp[index] != -1){
        return dp[index];
    }
        
        int oneAns1 = cost[index] + solve(index+1 , cost , dp);
        int secAns2 = cost[index]  + solve(index+2 , cost , dp);

        return dp[index] = min(oneAns1 , secAns2);
    }
      
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[0] , cost[1]);
        vector<int> dp(cost.size()+1,-1);
        int ans = min(solve(0 , cost  , dp) , solve(1 , cost , dp));
        return ans;
    }
};