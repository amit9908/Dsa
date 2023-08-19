class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        if(s==0)return {-1};
        vector<int> ans;
        long l=0,r=0,sum=0;
        while(r<n){
            if(sum+arr[r]<=s)sum+=arr[r++];
            else sum-=arr[l++];
            if(sum==s)return {l+1,r};
        }
        return {-1};
    }
};