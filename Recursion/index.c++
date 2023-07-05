#include <iostream>
#include <vector>
using namespace std;

void solve(int arr[] , int index , int  n , int target ,vector<int> &ans){
    if(index == n){
        return ;
    }

    if(arr[index] == target){
        ans.push_back(index);
    }

    solve(arr , index+1 , n , target , ans);

}

int main(){
    int arr[] = {1,3,4,1,5,4,1,1,1};
    vector<int> ans;
   
    int target = 10;
    //int ans = -1;
    int n = 9;
    solve(arr, 0 ,n , target  , ans);

    for(int i=0 ; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    
}