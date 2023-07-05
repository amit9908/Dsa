class Solution {
public:

   bool isPalindromic(string str){
       int i=0;
       int j=str.size()-1;

       while(i<j){
          char left = str[i];
          char  right = str[j];
          if(left != right){
              return false;
          }
          i++;
          j--;
       }

       return true;
   } 
   

    void solve(string s ,vector<vector<string>>& ans,vector<string> &output){
      if(s.length() == 0){
          ans.push_back(output);
          return;
        }

      for(int i=0 ; i<s.length() ; i++){
          string prefix = s.substr(0,i+1);
          string leftString = s.substr(i+1);
          if(isPalindromic(prefix)){
            output.push_back(prefix);
            solve(leftString , ans , output);
            output.pop_back();
          }
        }
         
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> output;
        solve(s, ans , output);
        return ans; 
    }
};