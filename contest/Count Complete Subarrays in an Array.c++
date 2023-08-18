class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(auto i:nums)
        {
            st.insert(i);
        }
        if(st.size()==1)return ((n*(n+1))/2);
        int t=st.size();
        int j;
        unordered_set<int> s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            j=i;
            while(j<n)
            {
                s.insert(nums[j]);
                if(s.size()==t)ans++;
                j++;
            }
            s.clear();
        }
        return ans;
    }
};