class Solution {
public:
  
   int solve(string w1 , string w2 , int i , int j ){
       if(i == w1.size() || j == w2.size()) return 0;
       


       int ans = 0;
       if(w1[i] == w2[j]){
           ans = 1 + solve(w1,w2,i+1,j+1);
       }else{
            ans = max(solve(w1,w2,i+1,j) , solve(w1,w2,i,j+1));
       }

       return ans;
   }
    
    int minDistance(string word1, string word2) {
        int i=0;
        int j=0;
        if(word1 == word2) return 0;
        int ans = solve(word1 , word2 , i , j );
        int finalAns = word1.size() - ans + word2.size() - ans;
        return finalAns;
    }
};