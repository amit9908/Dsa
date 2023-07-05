class Solution {
private:
   int greater(int n,vector<int>& num)
   {   
       int maxi = 0;  
       int i=0;
       while(num[i] != n)
       i++;
       for(int j=i+1;j<num.size();j++)
       {
           if(num[j] > n){
               return  num[j];
            }
           
       }
       return -1;
    
   }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++)
        {
            int temp=greater(nums1[i],nums2);
            ans.push_back(temp);
        } 
        return ans;
    }
};