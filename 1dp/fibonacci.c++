#include <iostream>
#include <vector>
using namespace std;

// recursion + memonization

// int solve(int n , vector<int>& dp){
//     if(n == 0) return 0;
//     if(n == 1)  return 1;
//     if(dp[n] != -1) return dp[n];

//     int ans = solve(n-1 , dp)  + solve(n-2 , dp);
//     return dp[n] = ans;
// }

// bottom up approach
// int solveTab(int nthTerm){
//     // first step create dp array
//     vector<int> dp(nthTerm+1, 0);

//     // second step analyze base case and update array
//     dp[0] = 0;
//     dp[1] = 1;

//     // find new range for the changing varible and copy paste logic code  from rec according
//     // step 3

//     for(int n=2 ; n <= nthTerm  ; n++){
//         int ans = dp[n-1]  + dp[n-2];
//         dp[n] = ans;
//     }

//     return dp[nthTerm];

// }

// optimisation
int solveTab(int nthTerm){

1st step remove replace dp arraywith your optimisation storage structure&& remove dp arr
    if(n == 0) return 1;
    if(n == 1) return 2;
    int prev1 = 1;
    int prev2 = 0;
    int index = 0;
    int curr;
    
step2 dp values -> replace -> prev1 ,prev2
    for(int n=2 ; n<=nthTerm ; n++){
        int ans = prev1 + prev2;

        curr = ans;

step3 take care of the movement and updation of prev1 , prev2
        prev2 = prev1;
        prev1 = curr;

    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;

    cout << solveTab(n) << endl;
}
