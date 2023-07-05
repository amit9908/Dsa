class Solution {
public:
 
    bool isSafe(int sum){
     
      int sqr = sqrt(sum);
      return(sqr*sqr == sum);
    }  

    void solve(vector<int> nums , int& count , int index){
        if(index >= nums.size()){
            count++;
    
        }

        for(int j=index ; j<nums.size() ; j++){
            if(j != index && nums[index] == nums[j]){
                continue;
            }

            swap(nums[index] , nums[j]);
            if(index == 0 || (index > 0 && isSafe(nums[index] + nums[index-1]))){
                solve(nums , count , index+1);
            }
            
        }
    }
    int numSquarefulPerms(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int count=0;
        solve(nums , count , 0);
        return count;
    }
};