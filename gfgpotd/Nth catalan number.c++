class Solution
{
public:
    const int mod = 1000000007;

    vector<unsigned long int> memo;

    unsigned long int process(int n) 
    {
        if (n == 0 || n == 1)
            return 1;

        if (memo[n] != 0) {
            return memo[n];
        }

        unsigned long int res = 0;
        for (int k = 0; k < n; k++)
        {
            res += (process(k) % mod) * (process(n - k - 1) % mod);
            res %= mod;
        }

        memo[n] = res;
        return res;
    }

    unsigned long int findCatalan(int n) 
    {
        memo.resize(n + 1, 0);
        unsigned long int result = process(n);
        return result;
    }
};