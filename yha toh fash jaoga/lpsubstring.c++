#include<iostream>
using namespace std;

int solve(string a , int start , int end){
    if(start == end) return 1;
    if(start > end) return 0;

    if(a[start] == a[end]){
        int remLen = end-start-1;
        if(remLen == solve(a , start+1 , end-1)){
            return 2 + remLen;
        }
    }

    return max( solve(a , start , end-1) ,  solve(a , start+1 , end));

}

int main(){
    string a = "babad";
    int ans = solve(a , 0 , a.size()-1);
    cout << ans << endl;
}