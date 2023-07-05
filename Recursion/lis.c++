#include <iostream>
using namespace std;

int solve(int *arr , int curr  ,int prev ,int n){

    if(curr == n){
        return 0;
    }

    int pick = 0;
    if(prev == -1 || arr[curr]  > arr[prev]){
        pick = 1 + solve(arr,curr+1,curr ,  n);
    }
    
    int notpick = 0 + solve(arr,curr+1 , prev , n);
    

    return max(pick , notpick);
    
}

int main(){
    int arr[] = {0,1,0,3,2,3};
    int n = 6;
     
    int prev = -1;
    int curr = 0;
    

    int ans = solve(arr , curr , prev , n);
    cout << ans << endl;
}