class Solution {
public:
    int f(int i, int j, string &str, string &txt, vector<vector<int>> &dp) {
        if (i >= str.size() || j >= str.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (str[i] == txt[j] && i != j) {
            return dp[i][j] = 1 + f(i + 1, j + 1, str, txt, dp);
        }
        
        return dp[i][j] = max(f(i + 1, j, str, txt, dp), f(i, j + 1, str, txt, dp));
    }

    int LongestRepeatingSubsequence(string &str) {
        int n = str.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        string txt(str.begin(), str.end());
        return f(0, 0, str, txt, dp);
    }
};
