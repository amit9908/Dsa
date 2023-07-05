class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    // int solve(int arr[], int n ,int index ,vector<int>& dp){
    //     if(index>=n)return 0;
        
    //     if(dp[index] != -1) return dp[index];
        
    //     int include = arr[index] + solve(arr , n ,index+2,dp);
    //     int exclude = 0 + solve( arr , n , index+1,dp);
        
    //     return dp[index] = max(include , exclude);
        
    // }
    int solve(int arr[], int n ,int i ){
        vector<int>dp(n+2 , 0);
        int next1=0;
        int next2=0;
        int curr;
        for(int index=n-1 ; index>=0 ; index--){
        int include = arr[index] + next2;
        int exclude = 0 + next1;
        
         curr = max(include , exclude);
         next2 = next1;
         next1 = curr;
        }
         return curr;
    }
    
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        // vector<int>dp(n+1 , -1);
        int ans = solve(arr , n , 0 );
        return ans;
    }
};
       