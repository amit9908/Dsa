class Solution
{
    public:
    int countFractions(int n, int num[], int den[])
    {
        unordered_map<float,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp.find((float) (den[i]-num[i])/den[i])!=mp.end()) ans+=mp[(float) (den[i]-num[i])/den[i]];
            mp[(float) num[i]/den[i]]++;
        }
        return ans;
    }
};