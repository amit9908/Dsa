class Solution {
public:
   
   int solve(vector<int>& num , int i , int j , vector<vector<int>>& dp){
       if(i > j) return 0;
       if(i == j) return num[i];
       if(dp[i][j] != -1) return dp[i][j];
        
        int opt1 = num[i] + min(solve(num,i+2 , j,dp) ,solve(num ,i+1 , j-1,dp));
        int opt2 = num[j] + min(solve(num ,i ,j-2,dp) , solve(num , i+1 ,j-1,dp));

    return dp[i][j] = max(opt1 , opt2);

   }
    
    bool PredictTheWinner(vector<int>& nums) {
        int j = nums.size() - 1;
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
        int player1 = solve(nums ,  0 , j , dp);
        int totalscore = 0;
        for(int i=0 ; i<nums.size() ; i++){
            totalscore += nums[i];
        }

        int player2 = totalscore - player1;
        if(player1 >= player2) return true;
        else return false;
        
    }
};