class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    // vector<int>freq(nums.size()+1 ,0);
    //  bool flag = false;
    //  for(int i=0 ; i<nums.size() ; i++){
    //      freq[nums[i]]++;
    //      if(freq[nums[i]] == 2){
    //          flag = true;
    //          return nums[i];
    //      }
    //  }
     
    //  return 0;

    while(nums[0] != nums[nums[0]]){
        swap(nums[0] , nums[nums[0]]);
    }
    return nums[0];
    }
};


    // Visited
    public static int findDuplicate_mark(int[] nums) {
        int len = nums.length;
        for (int num : nums) {
            int idx = Math.abs(num);
            if (nums[idx] < 0) {
                return idx;
            }
            nums[idx] = -nums[idx];
        }

        return len;
    }

 