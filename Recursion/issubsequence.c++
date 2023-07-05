class Solution {
public:

    int solve(string s ,  string t , int i , int j){
      if(i == s.size() || j == t.size()){
          return 0;
        }

        if(s[i] == t[j]){
            return 1+solve(s,t,i+1,j+1);
        }else{
            return solve(s,t,i,j+1);
        }
    
    }

    bool isSubsequence(string s, string t) {
        int ans = solve(s, t, 0 , 0);
        if(ans  == s.size()) return true;
        else return false;
    }
};