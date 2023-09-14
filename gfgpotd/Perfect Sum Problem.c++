#include <vector>

class Solution {
public:
    const int MOD = 1000000007;

    int solve(int index, int arr[], int n, int sum, std::vector<std::vector<int>>& dp) {
        if (index >= n) {
            if (sum == 0) {
                return 1;
            }
            return 0;
        }

        if (sum < 0) return 0;

        if (dp[index][sum] != -1) return dp[index][sum];

        // Include the current element in the subset
        int include = solve(index + 1, arr, n, sum - arr[index], dp);

        // Exclude the current element from the subset
        int exclude = solve(index + 1, arr, n, sum, dp);

        // Calculate the total count
        int totalCount = (include + exclude) % MOD;

        dp[index][sum] = totalCount;
        return totalCount;
    }

    int perfectSum(int arr[], int n, int sum) {
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(sum + 1, -1));
        return solve(0, arr, n, sum, dp);
    }
};