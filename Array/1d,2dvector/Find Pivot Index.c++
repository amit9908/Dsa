class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long sum=0 ;
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
        }
        long long ls=0;
        long long rs=sum; 
        for(int i=0; i<nums.size() ; i++){
            rs -= nums[i];
            if(ls == rs){
                return i;
            }
            ls += nums[i];
        }
        return -1;
    }
};