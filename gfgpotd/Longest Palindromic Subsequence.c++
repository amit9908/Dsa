class Solution{
  public:
    int solve(string& A , string& B , int i , int j,vector<vector<int>>& dp){
        if(i>=A.size() || j>=B.size())return 0;
        
        if(dp[i][j] != -1)return dp[i][j];
        
        if(A[i] == B[j]){
            return dp[i][j] = 1+solve(A,B,i+1 , j+1,dp);
        }
        
        return dp[i][j] = max(solve(A,B,i+1,j,dp),solve(A,B,i,j+1,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string B = "";
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        for(int i=n-1 ; i>=0 ; i--){
            B += A[i];
        }
        int ans = solve(A,B,0,0,dp);
        return ans;
    }
};



class Solution {
public:
     int longestPalinSubseq(string A) {
          int n=A.size();
          string B = A;
          reverse(B.begin(),B.end());
          vector<vector<int>>dp(n+1,vector<int>(n+1,0));
          
          for(int i=1;i<=n;i++){
              for(int j=1;j<=n;j++){
                  if(A[i-1]==B[j-1]) dp[i][j]=1+dp[i-1][j-1];
                  else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
              }
          }
          
          return dp[n][n];
    }
};

class Solution {
public:
     int longestPalinSubseq(string A) {
          int n=A.size();
          string B = A;
          reverse(B.begin(),B.end());
          //vector<vector<int>>dp(n+1,vector<int>(n+1,0));
          vector<int>curr(n+1,0);
          vector<int>prev(n+1,0);
          for(int i=1;i<=n;i++){
              for(int j=1;j<=n;j++){
                  if(A[i-1]==B[j-1]) curr[j]=1+prev[j-1];
                  else curr[j]=max(prev[j],curr[j-1]);
                }
                prev = curr;
              
          }
          
          return curr[n];
    }
};