class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
        unordered_map<long long,int> m;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                long long sum = a[i] + a[j];
                if(m.count(sum)) return 1;
                m[sum] = 1;
            }
        }
        return 0;
    }
};