//User function template for C++

class Solution
{
  public:
    bool isPossible(int a[] , int n , int k , long long sol){
        long long timeSum = 0;
        int c = 1;
        
        for(int i=0 ; i<n ; i++){
            if(a[i] > sol){
                return false;
            }
             if( a[i] + timeSum > sol){
                c++;
                timeSum = a[i];
                if(c > k)return false;
                
            }else{
                timeSum += a[i];
            }
        }
        
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        
 
        long long s = 0;
        long long e = 0;
        for(int i=0 ;i<n ; i++){
            e += arr[i];
        }
        
        long long ans = -1;
        long long mid = s+(e-s)/2;
        
        while(s<=e){
            
            if(isPossible(arr,n,k,mid)){
                ans = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
             mid = s+(e-s)/2;
        }
        
    }
};