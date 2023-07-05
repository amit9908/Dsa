#include <bits/stdc++.h>
using namespace std;

// int solve (int n , int a , int b , int c){
//     if(n == 0){
//         return 0;
//     }

//     if(n < 0){
//         return  INT_MIN;
//     }

//     int first = 1  + solve(n-a , a , b, c);
//     int second = 1 + solve(n-b , a , b ,c);
//     int third = 1 + solve(n-c, a , b, c);

//     return max(first,max(second,third));
// }

// int main(){
//     int n=10;
//     int a=9;
//     int b=7;
//     int c=11;

//     int ans = solve(n,a,b,c);
//     if(ans <= 0){
//         ans = -1;
//     }
//     cout << ans << endl;

// }

// int solve (int n , int a , int b , int c , vector<int>& dp){
//     if(n == 0){
//         return 0;
//     }

//     if(n < 0){
//         return  INT_MIN;
//     }

//     if(dp[n] != -1){
//         return dp[n];
//     }

//     int first = 1  + solve(n-a , a , b, c ,dp);
//     int second = 1 + solve(n-b , a , b ,c ,dp);
//     int third = 1 + solve(n-c, a , b, c , dp);

//     return dp[n] = max(first,max(second,third));
// }

// int main(){
//     int n=10;
//     int a=9;
//     int b=7;
//     int c=11;
//     vector<int> dp(n+1,-1);
//     int ans = solve(n,a,b,c);
//     if(ans <= 0){
//         ans = -1;
//     }
//     cout << ans << endl;

// }

// bottom down approach
int solve(int nth, int a, int b, int c)
{
    vector<int> dp(nth + 1, INT_MIN);
    dp[0] = 0;

    for (int n = 1; n <= nth; n++)
    {
        int first = 1 + dp[n - a];
        int second = 1 + dp[n - b];
        int third = 1 + dp[n - c];

        dp[n] = max(first, max(second, third));
    }

    return dp[nth];
}

int main()
{
    int n = 10;
    int a = 9;
    int b = 7;
    int c = 11;

    int ans = solve(n, a, b, c);
    if (ans == INT_MIN){
       cout << -1 << endl; 
    }else{
       cout << ans << endl;
    }
    
    
}