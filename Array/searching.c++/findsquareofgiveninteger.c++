#include <bits/stdc++.h>
using namespace std;

int findSquare(int n){
    int s = 0;
    int e = n;
    int mid = s+(e-s)/2;
    int ans = -1;

    while (s<=e)
    {
       if(mid * mid  == n){
        return mid;
       }
       else if(mid * mid > n){
        e = mid-1;
       }else{
        ans = mid;
        s = mid+1;
       }

       mid = s+(e-s)/2;
    }

    return ans;
    
}

int main(){
    int n;
    cin >> n ;

    int ans = findSquare(n);
    cout << ans << endl;

    int precision;
    cin >> precision ;
    double finalans = ans;
    double step = 0.1;

    for(int i =0 ; i<precision ; i++){
        for(double j=finalans ; j*j<=n ; j=j+step){
            finalans = j;
        }

        step /= 10.0;
    }

    cout <<  finalans << endl;

}