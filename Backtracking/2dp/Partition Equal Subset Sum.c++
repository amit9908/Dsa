class Solution {
public:
    // bool solve(vector<int>& nums , int index , int target , vector<vector<int>>& dp){
    //     if(index >= nums.size()){
    //         return 0;
    //     }
    //     if(target < 0){
    //         return 0;
    //     }
    //     if(target == 0){
    //         return 1;
    //     }

    //     if(dp[index][target] != -1) return dp[index][target];
        
    //     bool include = solve(nums , index+1 , target-nums[index] , dp);
    //     bool exclude = solve(nums , index+1 , target , dp);
        
    //     dp[index][target] = include || exclude;
    //     return dp[index][target];
    // }

    // bool solve(vector<int>& nums , int ind, int tar){
    //     vector<vector<int>> dp(nums.size()+1, vector<int>(tar + 1, 0));
    //     for(int index=0 ; index < nums.size() ; index++){
    //          dp[index][0] = 1;
    //     }

    //     for(int index=nums.size()-1 ; index>=0 ; index--){
    //         for(int target=1 ; target<=tar ; target++){
              
    //           bool include=0;
    //           if(target-nums[index] >= 0) {
    //             include = dp[index+1] [target-nums[index]];
    //           }
              
    //            bool exclude = dp[index+1] [target];;
        
    //            dp[index][target] = include || exclude;
    //         }
    //     }
    //     return dp[0][tar];
    // }


     
    bool solve(vector<int>& nums ,int tar){
         vector<bool>curr(tar+1 ,0);
         vector<bool>next(tar+1 ,0);
         
         curr[0] = 1;
         next[0] = 1;
        

        for(int index=nums.size()-1 ; index>=0 ; index--){
            for(int target=1 ; target<=tar ; target++){
              
              bool include=0;
              if(target-nums[index] >= 0) {
                include = next[target-nums[index]];
              }
              
               bool exclude = next[target];;
        
               curr[target] = include || exclude;
                
            }
             next = curr;
           
        }
        return curr[tar];
    } 



    
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i=0 ;i<nums.size() ; i++){
            total_sum += nums[i];
        }
        if(total_sum % 2 != 0) return false;
        int target = total_sum / 2;
        // vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
        // bool ans = solve(nums, 0, target);
        bool ans = solve(nums, target);
        return ans;
    }
};
