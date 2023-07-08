#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr){
    int s = 0;
    int e = arr.size()-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if(s == e){ // for {1,2,3,4,6,7}
            return s;
        }

        if(mid+1<=e && arr[mid]>arr[mid+1]){
            return mid;
        }

        if(mid-1>=s && arr[mid-1] > arr[mid]){
            return mid-1;
        }

        if(arr[s] > arr[mid]){
            e = mid-1;
        }else{
            s=mid+1;
        }

        mid = s+(e-s)/2;
    }

    return -1;
}

int main(){
    vector<int> arr{9,10,2,4,6,8};
    int ans = findPivot(arr);
    
    if(ans == -1){
        cout << "kuch gadbad hai" << endl;
    }
    else{
        cout << "Ans is at index" << ans << endl;
        cout << "Value of index" << arr[ans] << endl;
    }

    return 0;
}