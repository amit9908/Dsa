class Solution {
public:
    int numSquareHelper(int n ,vector<int>&dp){
        if( n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        int end = sqrt(n);
        int i=1;
        while(i <= end){
            int perfectSquare = i*i;
            int numPerfectSquare = 1 + numSquareHelper(n-perfectSquare ,dp);
            if(numPerfectSquare < ans){
               ans = numPerfectSquare;  
            }
            i++;
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        vector<int> dp(n+1 ,-1);
        int ans = numSquareHelper(n ,dp);
        return ans-1;
    }
};

// t.c -> 0(3n)
// s.c -> 0(n+1)