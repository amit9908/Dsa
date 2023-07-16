class Solution {
public:
    string solve(int n){
        if(n == 1) return "1";
        string s = solve(n-1);
        int cnt = 1;
        string ans ="";
        for(int i = 0; i<s.length(); i++){
            if(i<s.length() -1 && s[i] == s[i+1]){
                cnt++;
            }
            else {
                ans += char(cnt + '0');
                ans += s[i];
                cnt = 1;
            }
        }
        return ans;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};;