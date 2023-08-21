class Solution {
public:
    
    int find(vector<int>&A,int k){
        int start = 0;
        int len = 0;
        int ans =0 , n = A.size();
        
        for(int i=0;i<n;++i){
            if(i == 0)len++;
            else{
                int dif = (A[i]-A[i-1])-1;
                k-=dif;
                while(k<0){
                    k += ((A[start+1]-A[start])-1);
                    len--;
                    start++;
                }
                len++;
            }
            ans = max(ans,len);
        }
        
        return ans;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        map<int,vector<int>>idx;
        for(int i=0;i<n;++i){
            idx[nums[i]].push_back(i);
        }
        
        for(auto&x:idx){
            int val = find(x.second,k);
            ans = max(ans,val);
        }
        
        return ans;
    }
};