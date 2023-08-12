#include <iostream>
using namespace std;

int solve(int *arr , int curr  ,int prev ,int n){

    if(curr == n){
        return 0;
    }

    int pick = 0;
    if(prev == -1 || arr[curr]  > arr[prev]){
        pick = 1 + solve(arr,curr+1,curr ,  n);
    }
    
    int notpick = 0 + solve(arr,curr+1 , prev , n);
    

    return max(pick , notpick);
    
}

int main(){
    int arr[] = {0,1,0,3,2,3};
    int n = 6;
     
    int prev = -1;
    int curr = 0;
    

    int ans = solve(arr , curr , prev , n);
    cout << ans << endl;
}


class Solution {
public:
    int rec(vector<int>& nums, int i, int prev, vector<vector<int>>& dp)
    {
        if (i >= nums.size())
            return 0;
        if (dp[i][prev + 1] != -1)
            return dp[i][prev + 1];
        
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]){
         take = 1 + rec(nums, i + 1, i, dp);
        }


        int notTake = rec(nums, i + 1, prev, dp);

        return dp[i][prev + 1] = max(take, notTake);
    }

    int solve(int n, int arr[]) {
    vector<vector<int>> dp(n + 1,vector<int>(n + 1, 0));

    for (int curr = n - 1; curr >= 0; curr--) {
        for (int prev = curr - 1; prev >= -1; prev--) {
            int pick = 0, notPick = 0;

            if (prev == -1 || arr[curr] > arr[prev]) {
                pick = 1 + dp[curr + 1][curr + 1];
            }

            notPick = dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(pick, notPick);
        }
    }

    return dp[0][0]; // Return the result using proper indices
    }
   
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp (nums.size() + 1, vector<int> (nums.size() + 1, -1));

        return rec(nums, 0, -1, dp);
    }
};