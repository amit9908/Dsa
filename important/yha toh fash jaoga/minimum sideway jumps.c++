class Solution {
public:
      int solve(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n+1, 1e9));
    dp[0][n] = 0;
    dp[1][n] = 0;
    dp[2][n] = 0;
    dp[3][n] = 0;

    for (int currPos = n - 1; currPos >= 0; currPos--)
    {
        for (int currLane = 1 ; currLane <=3 ; currLane++)
        {

            int finalAns = 0;
            if (obstacles[currPos + 1] != currLane)
            {
                finalAns = dp[currLane][currPos + 1];
            }
            else
            {
                int ans = 1e9;
                for (int i = 1; i <= 3; i++)
                {
                    if (i != currLane && obstacles[currPos] != i)
                    {
                        ans = min(ans, 1 + dp[i][currPos+1]);
                    }
                }
                finalAns = ans;
            }

            dp[currLane][currPos] = finalAns;
        }
    }
    return min(dp[2][0],min(1+dp[1][0] ,1+dp[3][0]));
}



int minSideJumps(vector<int> &obstacles)
{
    int currLane = 2;
    int currPos = 0;
    int n = obstacles.size();
    // vector<vector<int>> dp(4, vector<int>(n , -1));
    return solve(obstacles);
}
};

class Solution {
public:
    int solve(vector<int>& obs,int currpos,int currLane){
        int n=obs.size()-1;
        if(currpos==n)
        return 0;

        int jump=0;
        if(obs[currpos+1]!=currLane)
        return solve(obs,currpos+1,currLane);
        else
        {
            int ans=INT_MAX;
            for(int i=1;i<=3;i++){
                if(currLane!=i && obs[currpos]!=i)
                {
                    ans=min(ans,1+solve(obs,currpos,i));
                }   
            }
            return ans;
        }
    }