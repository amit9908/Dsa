int solve(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<vector<int>> dp(4, vector<int>(n, INT_MAX));
    for (int i = 0; i <= 3; i++)
    {
        dp[i][n - 1] = 0;
    }

    for (int currLane = 1; currlane <= 3; currlane++)
    {
        for (int currPos = n - 1; currPos >= 0; currPos--)
        {

            int finalAns = 0;
            if (obstacles[currPos + 1] != currLane)
            {
                finalAns = dp[currLane][currPos + 1];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    if (i != currLane && obstacles[currPos] != i)
                    {
                        ans = min(ans, 1 + dp[i][currPos]);
                    }
                }
                finalAns = ans;
            }

            dp[currLane][currPos] = finalAns;
        }
    }
    return dp[2][0];
}



int minSideJumps(vector<int> &obstacles)
{
    int currLane = 2;
    int currPos = 0;
    int n = obstacles.size();
    // vector<vector<int>> dp(4, vector<int>(n , -1));
    return solve(obstacles);
}
}
;