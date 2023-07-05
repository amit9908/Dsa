class Solution {
public:
    void solve(vector<int>& nums , int& sum , int& xorAns , int index){
        if(index >= nums.size()){
            sum += xorAns;
            return ;
        }

        xorAns ^= nums[index];
        solve(nums , sum , xorAns , index+1);
        xorAns ^= nums[index];

        solve(nums , sum , xorAns , index+1);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        int xorAns = 0;
        int index = 0;
        solve(nums , sum , xorAns , index);
        return sum;
    }
};