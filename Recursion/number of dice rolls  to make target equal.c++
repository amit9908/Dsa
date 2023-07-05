class Solution {
public:
   int MOD = 1000000007;

// int solveUsingRec(int n , int k , int target){
//     // base case
//     if(n < 0)
//         return 0;

//     if(n==0 && target == 0)
//         return 1;

//     if(n==0 && target !=0)
//          return 0;
     
//      if(n != 0 && target == 0){
//          return 0;
//      }

//   int ans = 0;
//   for(int i = 1 ; i<=k ; i++){
//       int ans = ans + solveUsingRec(n-1 , k , target- i);
//   }
//   return ans;


// }

// t.c 0(kn)
// s.c 0(n)

   // DP solution . Top down
     
     
int solveUsingMemoization(int n ,int k , int target ,vector<vector<long long int>>&dp){
    // base case
    if(n < 0)
        return 0;

    if(n==0 && target == 0)
        return 1;

    if(n==0 && target !=0)
         return 0;
     
     if(n != 0 && target == 0){
         return 0;
     }

   // step 3: already exist
     if(dp[n][target] != -1){
         return dp[n][target];
     }

  int ans = 0;
  for(int i = 1 ; i<=k ; i++){

       int recAns = 0;
      if(target - i >= 0)
         recAns = solveUsingMemoization(n-1 , k , target- i , dp);

           ans = (ans % MOD + recAns % MOD ) % MOD;
  }
  

  // step 2 : store the answer in dp array.
  dp[n][target]= ans;
  return dp[n][target];

}


    int numRollsToTarget(int n, int k, int target) {
    // return  solveUsingRec(n ,  k , target);

    // create a dp array
    vector<vector<long long int >> dp(n+1 , vector<long long int>(target+1 , -1));
  

    int ans = solveUsingMemoization(n , k , target , dp);
    return ans;

    }
};