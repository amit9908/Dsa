#include<iostream>
using namespace std;

void solve(string &s , int i , int j , string &ans){
   if(i==j) return;
    solve(s , i+1 , j , ans);
    ans += s[i];

}

int main(){
    string s = "lund";
    int n = s.length();
    string ans = "";
    solve(s , 0 , n , ans);
    cout << ans << endl;
}
