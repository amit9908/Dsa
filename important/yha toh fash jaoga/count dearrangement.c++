// #define MOD 1000000007
#include <vector>
// long long int solve(int n , vector<long long int>& dp){
//     if(n == 1) return 0;
//     if(n == 2) return 1;
//     if(dp[n] != -1) return dp[n];

//     int ans = (((n-1)%MOD) * ((solve(n-2 , dp)%MOD)+(solve(n-1 , dp)%MOD))%MOD);
//     return dp[n] = ans;
// }

// long long int solve(int N){
//      vector<long long int> dp(N+1, 0);
//      dp[1] = 0;
//      dp[2] = 1;
    
//     for(int n=3 ; n<=N ; n++){
//      long long int ans = (((n-1)%MOD) * ((dp[n-2] % MOD)+(dp[n-1] % MOD))%MOD);
//      dp[n] = ans; 
//     }
    
//     return dp[N];

// }

const int MOD = 1000000007;

long long int solve(int N) {
    long long int prev1 = 1;
    long long int prev2 = 0;
    
    for(int n = 3; n <= N; n++) {
        long long int ans = ((n - 1) % MOD) * ((prev2 % MOD) + (prev1 % MOD)) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

long long int countDerangements(int n) {
    long long int ans = solve(n);
    return ans;
}

