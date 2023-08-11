class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int N = coins.size();
        vector<vector<int>> dp(N + 1, vector<int>(amount + 1, 0));

        // Base case: If the sum is 0, there's one way (empty set).
        for (int i = 0; i <= N; i++) {
            dp[i][0] = 1;
        }

        for (int index = N - 1; index >= 0; index--) {
            for (int s = 1; s <= amount; s++) {
                int include = (s - coins[index] >= 0) ? dp[index][s - coins[index]] : 0;
                int exclude = dp[index + 1][s];
                dp[index][s] = include + exclude;
            }
        }
        return dp[0][amount];
    }
};