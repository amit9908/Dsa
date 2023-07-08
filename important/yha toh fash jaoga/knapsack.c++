#include <bits/stdc++.h>
using namespace std;

// memoization
//  int solve( vector<int>& val , vector<int>& wt , int index , int cap ,vector<vector<int>>dp){
//      if(index == val.size() || cap == 0) return 0;
//      if(dp[index][cap] != -1) return dp[index][cap];

//     int include = 0;
//     if(cap >= wt[index]){
//        include = val[index]  + solve( val , wt ,index+1  , cap-wt[index] ,dp);
//     }

//     int exclude = 0 + solve( val , wt ,index+1 , cap , dp);

//     return dp[index][cap]  = max(include , exclude);

// }

//bottom down approach
// int solve(vector<int> &val, vector<int> &wt, int i, int c , int n)
// {
//     vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
//     // vector<int>next (c + 1, 0);
//     // vector<int>curr (c + 1, 0);
//     for (int index = n - 1; index >= 0; index--)
//     {
//         for (int cap = 0; cap <= c; cap++)
//         {
//             int include = 0;
//             if (cap >= wt[index])
//             {
//                 include = val[index] + dp[index+1][cap - wt[index]];
//             }
//             int exclude = 0 + dp[index+1][cap];
//             dp[index][cap] = max(include, exclude);
            
//         }
//     }

//     // for (int index = 0; index <= n; index++)
//     // {
//     //     for (int cap = 0; cap <= c; cap++)

//     //     {
//     //         cout << dp[index][cap] << " ";
//     //     }
//     //     cout << endl;
//     // }

//     return dp[i][c];
// }


// optimized and most optimized
int solve(vector<int> &val, vector<int> &wt, int i, int c , int n)
{
    // vector<vector<int>> dp(n + 1, vector<int>(c + 1, 0));
    // vector<int>next (c + 1, 0);
    vector<int>curr (c + 1, 0);

    for (int index = n - 1; index >= 0; index--)
    {
        // for (int cap = 0; cap <= c; cap++)
        for (int cap = c; cap >= 0; cap--)
        {
            

            if (cap >= wt[index])
            {
                // include = val[index] + next[cap - wt[index]];
                include = val[index] + curr[cap - wt[index]];
            }

            int exclude = 0 + curr[cap];

            curr[cap] = max(include, exclude);
            
        }
    //    next = curr;
    }

    // for (int index = 0; index <= n; index++)
    // {
    //     for (int cap = 0; cap <= c; cap++)

    //     {
    //         cout << dp[index][cap] << " ";
    //     }
    //     cout << endl;
    // }

    return curr[c];
}

int main()
{
    int n=3;
    vector<int> val, wt;

    val.push_back(60);
    val.push_back(100);
    val.push_back(120);

    wt.push_back(10);
    wt.push_back(20);
    wt.push_back(30);

    int capacity = 50;
    // vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    int ans = solve(val, wt, 0, capacity , n);
    cout << ans << endl;
}