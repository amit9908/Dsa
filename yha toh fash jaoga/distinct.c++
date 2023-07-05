class Solution {
public:

    int solve(string s , string t , int i , int  j  , int n , int m){
        if(j == m) return 1;
        if(i == n) return 0;

        if(s[i] == t[j]){
            return solve(s , t , i+1 , j+1 ,n , m)  + solve(s,t,i+1,j , n , m);
        }
        else return solve(s,t,i+1,j,n,m);
    }
    int numDistinct(string s, string t) {
        int i=0; 
        int j=0;
        int n=s.size();
        int m=t.size();

        int ans = solve(s , t , i, j , n , m);
        return ans;

    }
};