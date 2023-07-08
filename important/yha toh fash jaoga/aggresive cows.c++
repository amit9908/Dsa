// User function Template for C++

class Solution {
public:

    bool isPossible(int n , int k , vector<int> s , int sol){
        int c = 1;
        int pos = s[0];
        
        for(int i=1 ; i<n ; i++){
            if(s[i]-pos >= sol){
                c++;
                pos = s[i];
            }
            if(c == k) return true;
            
        }
        
        return false;
    }

    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin() , stalls.end());
        int s = 0;
        int e = stalls[n-1] - stalls[0];
        int mid = s+(e-s)/2;
        int ans = -1;
        
        while(s<=e){
            if(isPossible(n,k,stalls,mid)){
                ans = mid;
                s = mid+1;
            }else{
                e = mid-1;
            }
            
             mid = s+(e-s)/2;
        }
        
        return ans;
    }
};