#include <iostream>
using namespace std;

int solve(int i  , int *arr , int diff){
    if(i < 0) return 0;

    int ans=0;

    for(int k=i-1 ; k>=0 ; k--){
        if(arr[i] - arr[i-1] == diff){
            ans = max(ans , 1+solve(k , arr , diff));
        }
    }
   
   return ans;


}

int main(){
    int arr[] = {9 , 4 , 7 , 2 ,10};
    int n = 5;
    
    int ans = 0;
    for(int i=0 ; i<n ; i++){
        for(int j=i+1 ; j<n ; j++){
            int diff = arr[j] - arr[i];
          ans = max(ans , 2+solve(i , arr , diff ));
        }
    }

    cout << ans <<  endl;
}
