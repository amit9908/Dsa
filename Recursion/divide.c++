#include <iostream>
using namespace std;

void solve(int *arr , int s, int e){
    if(s == e){
        cout << arr[s] << endl;
        return;
    }
    
    for(int i=s ; i<=e ; i++){
        cout << arr[i] << "";
    }cout<<endl;
     

    int mid = s+(e-s)/2;
   

    solve(arr, s ,mid);



    
}

int main(){
    int arr[] = {2,8,8,9,0,1};
    int size = 6;
    solve(arr , 0 , size-1);
    
}