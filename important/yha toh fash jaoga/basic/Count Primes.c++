
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

The square root (sqrt()) function is used in the given code to optimize the primality check algorithm.

In the isPrime() function, instead of iterating from 2 to n-1 to check for divisibility, the loop iterates only up to the square root of n (sqrtN). This optimization reduces the number of iterations required to determine whether a number is prime or not.

Here's why it works:

Any non-prime number n can be expressed as a product of two factors, a and b, such that n = a * b. At least one of these factors, a or b, must be less than or equal to the square root of n.

If both a and b are greater than the square root of n, their product would be greater than n, which is not possible. Therefore, at least one factor must be less than or equal to the square root of n.

By iterating up to the square root of n (sqrtN), the isPrime() function checks all possible factors of n that are less than or equal to sqrtN. If a factor is found, the function immediately returns false, indicating that the number is not prime.

If no factor is found up to sqrtN, the function returns true, indicating that the number is prime.

Using the square root optimization reduces the time complexity of the primality check algorithm from O(n2) to approximately O(n*sqrt(n)), significantly improving the performance for larger values of n

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

