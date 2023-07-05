#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> arr{5,3,4,8,2,8};
    int n = arr.size();
    
    for(int i=0 ; i<n-1 ; i++){
        int minIndex = i;
        for(int j=i+1 ; j<n ; j++){
            if(arr[j] < arr[i]){
                minIndex = j;
            }
        }
        swap(arr[i] , arr[minIndex]);
    }

    for(int i=0 ; i<arr.size() ; i++){
        cout << arr[i] << "";
    }

}