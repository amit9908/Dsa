class Solution {
public:
    
    int solve(string a ,string b , int i , int j){
        if(i == a.length()) return b.length()-j;
        if(j == b.length()) return a.length()-i;

        if(a[i] == b[j]){
            return solve(a,b,i+1,j+1);
        }
        
        int insert = 1 + solve(a,b,i,j+1);
        int del = 1 + solve(a,b,i+1 ,j);
        int replace = 1 + solve(a,b,i+1,j+1);

        return min(insert,min(del,replace));
    }
    
    int minDistance(string word1, string word2) {
        int ans = solve(word1 , word2 , 0 , 0);
        return ans;
    }
};