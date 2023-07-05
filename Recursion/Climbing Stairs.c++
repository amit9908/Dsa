class Solution {
public:
    int solution(int n, vector<int> &dp){
        if (n==0) return 1;
        if (n<0) return 0;
        if (dp[n]!=-1) return dp[n];
        int ans = 0;
        ans+=solution(n-1,dp);
        ans+=solution(n-2,dp);
        return dp[n] = ans;
    }

    int climbStairs(int n)
    {
        vector<int>dp(n+1,-1);
        return solution(n,dp);
    }
};