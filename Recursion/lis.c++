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


class Solution
{
public:
    int solve(int n, int arr[]) {
    std::vector<int> currRow(n + 1, 0);
    std::vector<int> nextRow(n + 1, 0);

    for (int curr = n - 1; curr >= 0; curr--) {
        for (int prev = curr - 1; prev >= -1; prev--) {
            int pick = 0, notPick = 0;

            if (prev == -1 || arr[curr] > arr[prev]) {
                pick = 1 + nextRow[curr + 1];
            }

            notPick = nextRow[prev + 1];
            currRow[prev + 1] = std::max(pick, notPick);
        }
        nextRow = currRow;
    }

    return nextRow[0];
}

    int longestSubsequence(int n, int a[]) {
       // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        //int ans = solve(n, a, -1, 0, dp);
        int ans = solve(n, a);
        return ans;
    }
};


   class Solution
{
public:
    int solve(int n, int a[]){
        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }

        return ans.size();
    }
    int longestSubsequence(int n, int a[]) {
       // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        //int ans = solve(n, a, -1, 0, dp);
        int ans = solve(n, a);
        return ans;
    }
};

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp (nums.size() + 1, vector<int> (nums.size() + 1, -1));

        return rec(nums, 0, -1, dp);
    }
};