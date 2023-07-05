class Solution {
public:
    // int solve(int index , vector<int>& cost  ,vector<int>& dp){
    //     if(index == cost.size()-1  || index == cost.size()-2){
    //         return cost[index];
    //     }
        

    //     if(index>=cost.size()){
    //         return 0;
    //     }

    //     if(dp[index] != -1){
    //     return dp[index];
    // }
        
    //     int oneAns1 = cost[index] + solve(index+1 , cost , dp);
    //     int secAns2 = cost[index]  + solve(index+2 , cost , dp);

    //     return dp[index] = min(oneAns1 , secAns2);
    // }

    int solve(int ind , vector<int>& cost ){
        // vector<int> dp(cost.size()+2,0);
        // dp[cost.size()-1] = cost[cost.size()-1];
        // dp[cost.size()-2] = cost[cost.size()-2];
        
        int curr;
        int next1=0;
        int next2=0;
        for(int index = cost.size()-1 ; index>=0 ; index--){

        int oneAns1 = cost[index] + next1;
        int secAns2 = cost[index]  + next2;

        curr = min(oneAns1 ,secAns2);
        next2 = next1;
        next1 = curr;
        }
        
    // int solve(int index , vector<int>& cost  ,vector<int>& dp){
    //     if(index == cost.size()-1  || index == cost.size()-2){
    //         return cost[index];
    //     }
        

    //     if(index>=cost.size()){
    //         return 0;
    //     }

    //     // int solve(int index , vector<int>& cost  ,vector<int>& dp){
    //     if(index == cost.size()-1  || index == cost.size()-2){
    //         return cost[index];
    //     }
        

    //     if(index>=cost.size()){
    //         return 0;
    //     }

    //     if(dp[index] != -1){
    //     return dp[index];
    // }
        
    //     int oneAns1 = cost[index] + solve(index+1 , cost , dp);
    //     int secAns2 = cost[index]  + solve(index+2 , cost , dp);

    //     return dp[index] = min(oneAns1 , secAns2);
    // }    if(dp[index] != -1){
    //     return dp[index];
    // }
        
    //     int oneAns1 = cost[index] + solve(index+1 , cost , dp);
    //     int secAns2 = cost[index]  + solve(index+2 , cost , dp);

    //     return dp[index] = min(oneAns1 , secAns2);
    // } return min(next1,next2);

    }  

    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size() == 2) return min(cost[0] , cost[1]);
        // vector<int> dp(cost.size()+1,-1);
        int ans = min(solve(0 , cost ) , solve(1 , cost));
        return ans;
    }
}