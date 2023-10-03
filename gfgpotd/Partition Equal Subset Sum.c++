class Solution {
public:
    bool subsetSum(int index, int N, int arr[], int targetSum, vector<vector<int>>& dp) {
        if (targetSum == 0) {
            return true;
        }
        if (index >= N || targetSum < 0) {
            return false;
        }
        
        if(dp[index][targetSum] != -1) return dp[index][targetSum];
        // Include the current element in the subset
        bool include = subsetSum(index + 1, N, arr, targetSum - arr[index] ,dp);

        // Exclude the current element from the subset
        bool exclude = subsetSum(index + 1, N, arr, targetSum ,dp);

        // Either include or exclude the current element
        return dp[index][targetSum] = include || exclude;
    }

    bool equalPartition(int N, int arr[]) {
        int totalSum = 0;
        for (int i = 0; i < N; i++) {
            totalSum += arr[i];
        }

        // If the total sum is odd, we can't divide it into equal partitions
        if (totalSum % 2 != 0) {
            return false;
        }

        int targetSum = totalSum / 2;
        vector<vector<int>>dp(N+1 , vector<int>(targetSum+1 , -1));
        return subsetSum(0, N, arr, targetSum,dp);
    }