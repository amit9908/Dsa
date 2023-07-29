class Solution {
public:
    vector<pair<int,int>> Op = {{100,0} , {75,25} , {50,50} , {25,75}};
    double solve(double A , double B , vector<vector<double>>& dp){
        if(A <= 0 && B <= 0) return 0.5;
        if(A <= 0) return 1;
        if(B <= 0) return 0.0;
        if(dp[A][B] != -1.0) return dp[A][B];
        double prob = 0.0;
        for(auto &i : Op){
          int A_Taken = i.first;
          int B_Taken = i.second; 
          prob += solve(A-A_Taken , B-B_Taken ,dp);
        }

        return dp[A][B] = 0.25 * prob;

    }
    double soupServings(int n) {
        if(n >= 5000)return 1;
        vector<vector<double>>dp(n+1 , vector<double>(n+1 , -1.0));
        return solve(n , n , dp);
    }
};