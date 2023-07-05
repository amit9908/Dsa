
// #time complexity O(root n)
class Solution {
public:
    bool isPrime(int n){
        // if(n<=1) return false;
        int sqrtN = sqrt(n);
        for(int i=2; i<=sqrtN ; i++){
              if(n%i == 0){
                  return false;
              }
        }
        return true;
    }
    
    int countPrimes(int n) {
        int c=0;
       for(int i=2 ; i<n ; i++){
           if(isPrime(i)){
              ++c;
           }
       }
       return c;
    }
}; 

// #time complexity O(n(log (logn))
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;
        int ans = 0;

        for(int i=2 ; i<n ; i++){
            if(prime[i]){
                ans++;

                int j=2*i;
                while(j<n){
                   prime[j]=false;
                   j+=i;
                }
            }
        }
       return ans; 
                
    }
};


// optimizing (inner loop)
class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return 0;
        vector<bool>prime(n,true);
        prime[0]=prime[1]=false;
        int ans = 0;

        for(int i=2 ; i<n ; i++){
            if(prime[i]){
                ans++;

                int j=i*i;
                while(j<n){
                   prime[j]=false;
                   j+=i;
                }
            }
        }
       return ans; 
                
    }
};

