class Solution {
public:
    vector<bool> segSieve(int n) {
        vector<bool> sieve(n + 1, true);
        sieve[0] = sieve[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if(sieve[i]){
                int j = i * i;
                while (j < n) {
                    sieve[j] = false;
                    j += i;
                }
            }
        }
        return sieve;
    }

    long long primeProduct(long long L, long long R) {
        vector<bool> ss = segSieve(sqrt(R));
        vector<int> basePrime;
        long long int ans = 1;
        long long mod = 1e9 + 7;

        for (int i = 0; i < ss.size(); i++) {
            if (ss[i]) {
                basePrime.push_back(i);
            }
        }
        
        vector<bool> segS(R - L + 1, true);
        // if (L == 0 || L == 1) {
        //     segS[L] = false;
        // }
        
    for (auto prime : basePrime) {

        long long first_mul = (L / prime) * prime;
        if (first_mul < L) {
            first_mul += prime;
        }
            
        long long j = max((long long)(prime*prime) , first_mul);
        while(j<=R)
        {
                    segS[int(j-L)] = false;
                    j+=prime;
        }
    }

        for (int i = 0; i < segS.size(); i++) {
            if (segS[i] == 1) {
                ans = (ans * (i+L)) % mod;
                // ans = ans % mod;
            }
        }

        return ans;
    }
};