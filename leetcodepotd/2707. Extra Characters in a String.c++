class Solution {
public:
    unordered_set<string> st;
    int n;
    
    int solve(string &s, int idx ,  vector<int>& dp) {
        if (idx >= n) 
            return 0;
        if(dp[idx] != -1) return dp[idx];
        string currStr = "";
        int minExtra = n;
        
        for (int i = idx; i < s.size(); i++) {
            
            currStr.push_back(s[i]);

            int currExtra = (st.find(currStr) == st.end()) ? currStr.length() : 0;
            int nextExtra = solve(s, i + 1 ,dp);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        
        return dp[idx] = minExtra;
    }
    
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        
        for(string &word : dictionary) {
            st.insert(word);
        }
        vector<int>dp(n+1 , -1);
        return solve(s, 0 ,dp);
    }
};