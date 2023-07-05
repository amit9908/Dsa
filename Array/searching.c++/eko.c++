#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<long long int> t , long long int m , long long int sol){
    long long wood = 0;

    for(int i=0 ; i<t.size() ; i++){
        if(t[i] > sol){
         wood += t[i]-sol;
        }
    }
    return wood >= m;

}

long long int maxSawBlade(vector<long long int>trees , int m){
    long long int start = 0;
    long long int end = 0;
    for(int i=0 ; i<trees.size() ; i++){
        end = max(end,trees[i]);
    }
    long long int mid = start+(end-start)/2;
    long long int ans = -1;

    while(start <= end){
        if(isPossible(trees , m , mid)){
            ans = mid;
            start = mid+1;
        }else{
            end = mid-1;
        }
    }

    return ans;

}

int main(){
    long long int n , m;
    cin >> n >> m;
    vector<long long int> trees;
    while(n--){
        long long int height;
        cin >> height ;
        trees.push_back(height);
    }

    cout << maxSawBlade(trees,m) << endl;
    return 0;
}