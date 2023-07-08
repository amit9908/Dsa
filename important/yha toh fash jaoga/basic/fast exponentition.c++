// normal solution to find a^b ->O(b);(slow exponentition)
for(int i=0 ; i<b ; i++){
    ans*=a;
}
cout >> ans ; endl

// better solution to find a^b ->O(log b);(dfast exponention)
int ans =1;
while(b>0){
    // checking for odd conditon
    if(b&1){    
      ans = ans*a;
    }
    a=a*a;
    // b>>=1; at this step b is getting divided by 2;
}
return ans;



// Modular Exponentiation for large numbers
class Solution
{
	public:
		long long int PowMod(long long int x,long long int n,long long int M)
		{
		    // Code here
		    long long int ans = 1;
		    while(n >0){
		        if(n&1){
		            ans = (ans*x)%M;
		        }
		        x = (x*x)%M;
		        n>>=1;
		    }
		    return ans%M;
		}
};



// recursive
int nCr(int n, int r)
{
    if (r == 0 || n == r)
    {
        return 1;
    }
    else
    {
        return (nCr(n - 1, r - 1) + nCr(n - 1, r))%mod;
    }
}

// memo
// mod = 1e9+7 and dp[n+1][n+1] all elements are set to -1    
int solve(int n, int r,vector<vector<int>> &dp){
        if(r == 0 || r == n){
            return 1;
        }
        if(dp[n][r] != -1)
            return dp[n][r];
        return dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
    }


// tabulation
// mod = 1e9+7   
 int nCr(int n, int r){
        // code here
        if(r>n)return 0;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        for(int i = 0; i <= n; i++){
            dp[i][0] = 1;
            dp[i][i] = 1;
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= r; j++){
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
            }
        }
        return dp[n][r]%mod;
        
    }

//space optimisation
 int nCr(int n, int r){
        // code here
        if (r > n)
            return 0;
        vector<int> prev(r+1),curr(r+1);
        prev[0] = curr[0] = 1;
        if(r == n){
            prev[r] = curr[r] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= r; j++)
            {
                curr[j] = (prev[j - 1] + prev[j])%mod;
            }
            prev = curr;
        }
        return prev[r];
        
    } 
