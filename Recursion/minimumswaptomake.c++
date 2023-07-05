class Solution {
public:

    int solve(vector<int>& nums1, vector<int>& nums2 , int prev1 , int prev2 , int index){
        if(index == nums1.size()) return 0;

        int swap = INT_MAX;
        int noswap = INT_MAX;
        
        if(nums1[index] > prev1 && nums2[index] > prev2){
            noswap= 0 + solve(nums1 , nums2 , nums1[index] , nums2[index] , index+1);
        }
        
         if(nums1[index] > prev2 && nums2[index] > prev1){
             swap = 1 + solve(nums1 , nums2 , nums2[index] , nums1[index] , index+1);
        }

        return min(swap,noswap);
        
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        int prev1= -1;
        int prev2 = -1;
        int index = 0;
        return solve(nums1 , nums2 , prev1 , prev2 , index);
    }
};