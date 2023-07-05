// memoization
// class Solution {
// public:
    
//     int solve(int index , vector<int>& nums , vector<int>& dp ){
//         if(index >= nums.size()){
//             return 0;
//         }
        
//         if(dp[index] != -1){
//             return dp[index];
//         }
        
//         int include =  nums[index] + solve(index+2 , nums , dp);

//         int exclude = 0 + solve(index+1 , nums  ,dp);

//         return dp[index] = max(include ,exclude);

//     }
    
//     int rob(vector<int>& nums) {
//         vector<int>dp(nums.size() , -1);
//         int ans = solve(0 , nums , dp);
//         return ans;

//     }
// };



// bottom down approach
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         vector<int>dp(n+2 , 0);
   
//         for(int index=n-1 ; index>=0 ; index--){
//         int include =  nums[index] + dp[index+2];

//         int exclude = 0 + dp[index+1];

//         dp[index] = max(include ,exclude);

//         }

//         return dp[0];

//     }
// };


// optimisation
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         int curr;
//         int next1 = 0;
//         int next2 = 0;
//         // vector<int>dp(n+2 , 0);
   
//         for(int index=n-1 ; index>=0 ; index--){
//         int include =  nums[index] + next2;

//         int exclude = 0 + next1;

//         curr = max(include ,exclude);

//         next2 = next1;
//         next1 = curr;

//         }

//         return curr;

//     }
// };