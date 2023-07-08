class Solution {
public:
    bool solve(int index , string s , set<string> st  , vector<int> dp){
            if(index == s.length()){
             return true;
            }
            
            if(dp[index] != -1){
               return dp[index] ;
            }
            
            string temp = ""; 
            for(int j=index ; j<s.length() ; j++){
                temp+=s[j];
                if(st.find(temp) !=  st.end()){
                   if (solve(j+1 , s , st , dp )){
                       return dp[index] =  true;
                   }
           
                }
            }

            return dp[index] = false;
    
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto str : wordDict){
            st.insert(str);
        }
        vector<int> dp(s.size()+1 , -1);
        return solve(0 , s , st , dp);
         
    }
};


class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n=s.length();
        unordered_map<string,int> mp;
        for(auto i:dict)mp[i];
        
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;--i){
            string temp;
            for(int j=i;j<n;j++){
                temp.push_back(s[j]);
                dp[i]|=(mp.count(temp) && dp[j+1]);
            }
        }
        return dp[0];
    }
};