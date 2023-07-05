

#include <iostream>
using namespace std;

int binarySearch(int nums[], int s ,int e , int target){
       int mid = s+(e-s)/2;
       while(s<=e){
           if(nums[mid] == target){
               return mid;
           }

           if(nums[mid] < target){
               s = mid+1;
           }else{
               e = mid-1;
           }
            mid = s+(e-s)/2;
       }
       return -1;
}

int expSearch(int a[] , int n , int x){
    if(a[0] == x) return x;
    int i=1;

    while (i<n && a[i] <= x)
    {
        i=i*2;
    }
    return binarySearch(a,i/2,min(i,n-1),x);
}

int main(){
    int a[] = {3,4,5,6,11,13,14,15,56,70};
    int n = sizeof(a)/sizeof(int);
    int x = 13;
    int ans = expSearch(a,n,x);
    cout<<ans<<endl;
    return 0;
}