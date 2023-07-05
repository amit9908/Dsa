class Solution {
public:
   
    void solve(int index , string s  , set<string> st , vector<string>& res , string temp ){
        if(index == s.length()){
            temp.pop_back();
            res.push_back(temp);
            return;
        }
        
        string subString = "";
        for(int i=index; i<s.length() ; i++){
            subString.push_back(s[i]);
            if(st.count(subString)){
                solve(i+1 , s , st , res , temp + subString +" ");
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<string> result;
        for(auto str:wordDict){
            st.insert(str);
        }
        string temp = "";
        
        solve(0 , s , st , result , temp);
        return result;

    }
};