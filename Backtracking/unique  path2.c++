//Recursive solution
 int helper(vector<vector<int>>& obstacleGrid, int i, int j){
        if( i < 0 or j < 0) return 0;

        if(obstacleGrid[i][j] == 1 ) return 0;

        if(i == 0 && j == 0) return 1;
        
        //if(obstacleGrid[i][j] == 1) return 0;

        int up = helper(obstacleGrid, i-1, j);
        int left = helper(obstacleGrid, i, j-1);

        return up+left;
        
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return helper(obstacleGrid, obstacleGrid.size() - 1, obstacleGrid[0].size() - 1);
        
    }
//----------------------------------------------------------------
//DP with memoization
    int helper(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo){
        if( i < 0 or j < 0) return 0;

        if(obstacleGrid[i][j] == 1 ) return 0;

        if(i == 0 && j == 0) return 1;

        if(memo[i][j] != -1) return memo[i][j];

        int up = helper(obstacleGrid, i-1, j, memo);
        int left = helper(obstacleGrid, i, j-1, memo);

        memo[i][j] = up + left;

        return memo[i][j];
        

    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> memo(row, vector<int>(col, -1));

        return helper(obstacleGrid, row - 1, col - 1, memo);
        
    }

//-----------------------------------------------------------
//DP with Tabulation
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                    continue;
                } 
                if(i==0 && j==0){
                    dp[i][j] = 1;
                    continue;
                }
                int down = 0;
                int right = 0;
                if(i>0){
                    down = dp[i-1][j];
                }
                if(j>0){
                    right = dp[i][j-1];
                }
                dp[i][j] = down + right;
            }
        }
        return dp[row-1][col-1];
    }

//-------------------------------------------------------------
class Solution {
public:
    //DP with Tabulation and space optimization
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();
        vector<int> prev(col, 0);

        for(int i = 0; i < row; i++){
            vector<int> temp(col, 0);

            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j] == 1){
                    temp[j] = 0;
                    continue;
                } 
                if(i==0 && j==0){
                    temp[j] = 1;
                    continue;
                }
                int down = 0;
                int right = 0;
                if(i>0){
                    down = prev[j];
                }
                if(j>0){
                    right = temp[j-1];
                }
                temp[j] = down + right;
            }
            prev = temp;
        }
        return prev[col-1];
    }
};