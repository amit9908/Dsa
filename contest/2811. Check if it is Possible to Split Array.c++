class Solution {
public:
    bool isValid(int start  , int end , vector<int>& nums, int m){
        int sum = 0;
        for(int i=start ; i<=end ; i++){
            sum += nums[i];
        }
        return sum >= m;
    }
    bool solve(int start  , int end , vector<int>& nums, int m ,vector<vector<int>>& dp){
        if(start ==  end) return true;

        if(!isValid(start , end , nums , m)){
            return false;
        }

        if(dp[start][end] != -1)return dp[start][end];

        bool res = false;
        for(int i=start ; i<end ; i++){
            bool left = solve(start , i , nums , m ,dp);
            bool right = solve(i+1 , end , nums , m ,dp);
            if(left && right){
                res = true;
                break;
            }
        }
        return dp[start][end] = res;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n <= 2) return true;
        vector<vector<int>>dp(n , vector<int>(n , -1));
        bool ans = solve(0 , n-1 , nums , m , dp);
        return ans;
        
    }
}



class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(n <= 2) return true;

        for(int i=1 ; i<n ; i++){
            if(nums[i] + nums[i-1] >= m){
                return true;
            }
        }
        return false;
    }
};