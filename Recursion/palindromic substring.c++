class Solution {
public:
    string s;
    int dp[1002][1002];
    bool isPalindrome( int i, int j) {
        while (i <= j) {
        if (s[i] != s[j]) {
            return false;
        }
            i++;
            j--;
        }
        return true;
    }
    
    int rec(int i, int j)
    {
    
        if (i > j || i < 0 || j >= s.length()) {
        return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
    
        int count = 0;
    
        if (isPalindrome( i, j)) {
        count = 1;
        }
    
        count += (rec( i, j - 1) + rec( i + 1, j) - rec(i + 1, j - 1)); 
        return dp[i][j] = count;
        
    }
    int countSubstrings(string st) {
         s = st;
         memset(dp, -1,sizeof(dp));
         int n = s.length();
         return rec(0, n - 1);
    }
};