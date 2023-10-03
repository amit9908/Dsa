class Solution
{
public:
// memo
    int solve(vector<vector<char>> &mat, int i, int j, int &maxi, vector<vector<int>> &dp)
    {
        if (i >= mat.size() || j >= mat[0].size())
        {
            return 0;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int right = solve(mat, i, j + 1, maxi, dp);
        int diagonal = solve(mat, i + 1, j + 1, maxi, dp);
        int down = solve(mat, i + 1, j, maxi, dp);

        if (mat[i][j] == '1')
        {
            int side = 1 + min(right, min(diagonal, down));
            maxi = max(side, maxi);

            return dp[i][j] = side;
        }
        else
            return dp[i][j] = 0;
    }

    // bottom

    int solve(vector<vector<char>> &matrix, int a, int b, int &maxi)
    {
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));

        for (int i = matrix.size() - 1; i >= 0; i--)
        {
            for (int j = matrix[0].size() - 1; j >= 0; j--)
            {
                int right = dp[i][j + 1];
                int diagonal = dp[i + 1][j + 1];
                int down = dp[i + 1][j];

                if (matrix[i][j] == '1')
                {
                    int side = 1 + min(right, min(diagonal, down));
                    maxi = max(side, maxi);

                    dp[i][j] = side;
                }
                else
                    dp[i][j] = 0;
            }
        }

        return dp[a][b];
    }

    int maximalSquare(vector<vector<char>> &matrix)
    {
        int maxi = 0;
        // vector<vector<int>>dp(matrix.size(),vector<int>(matrix[0].size(),-1));
        solve(matrix, 0, 0, maxi);
        return maxi * maxi;
    }
};