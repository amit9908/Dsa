class Solution{
public: 
    long long int largestPrimeFactor(int N){
        // code here
        long long ans=1;
        int m=N;
        for(int i=2;i*i<=m;i++)
        {
            while(N%i==0)
            {
                ans=i;
                N=N/i;
            }
        }
        // ans=max(ans,N);
        ans=(ans>N)?ans:N;
        return ans;
    }
};