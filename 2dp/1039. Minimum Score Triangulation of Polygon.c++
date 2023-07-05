class Solution {
public:
   
//    int solve(vector<int>& v , int i , int j , vector<vector<int>>& dp){
//        if(i+1 == j) return 0;
//        if(dp[i][j] != -1) return dp[i][j];

//        int mini=INT_MAX;
//        for(int k=i+1 ; k<j ; k++){
//            mini = min(mini , v[i]*v[k]*v[j] + solve(v , i , k ,dp) + solve(v, k , j ,dp));
//        }

//        return dp[i][j] = mini;
//    }


   int solve(vector<int>& values){
       vector<vector<int>> dp(values.size()+1 , vector<int>(values.size()+1 , 0));
         
        for(int i=values.size()-1 ; i>=0 ; i--){
            for(int j=i+2 ; j<values.size() ; j++){
                 int mini=INT_MAX;
                 for(int k=i+1 ; k<j ; k++){
                      mini = min(mini , values[i]*values[k]*values[j] + dp[ i ][k] + dp[k][j]);
                }

                 dp[i][j] = mini;
            }
        }

        return dp[0][values.size()-1];
   }
   
    
    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size()+1 , vector<int>(values.size()+1 , -1));
        //  return solve(values , 0 , values.size()-1 , dp);
        return solve(values);
    }
};