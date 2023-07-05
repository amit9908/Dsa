#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>v){
    int start = 0;
    int end = v.size()-1;
    int mid = start+(end-start)/2;
    int target = 4;
    int index=-1;

    while(start<=end){
        if(v[mid] == target){
            index=mid;
            start = mid+1;
        }
        else if(v[mid] < target){
             start = mid+1;
        }else if(v[mid] > target){
            end = mid-1;
        }
        mid = start+(end-start)/2;
    }

    return index;
}

int main(){
    vector<int>v{1,2,3,3,3,4,4,4,4,5,6};
    int ans = solve(v);
    cout << ans << " ";


}