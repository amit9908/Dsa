class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i=0 ; i<32 ; i++){
            int countOdd = 0 ,countEven = 0;
            for(int j=0 ; j<nums.size() ; j++){
                  if((1<<i) & nums[j])countOdd++;
                  else countEven++;
            }
            if(countOdd % 3){
               ans |= (1<<i);
            }
        }
        return ans;
        
    }
};