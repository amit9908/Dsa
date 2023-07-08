class Solution {
public:
    int findMax(vector<int>& nums , int skipIndex){
       int currLen = 0;
       int maxLen =  0;

       for(int i=0 ; i<nums.size() ; i++){
           if(i == skipIndex) continue;
           if(nums[i] == 1){
               currLen++;
               maxLen = max(maxLen , currLen);
           }else{
               currLen = 0;
           }
       }
      return maxLen;
    }
    int longestSubarray(vector<int>& nums) {
        int finalAns = 0;
        int countZero = 0;

        for(int i=0; i<nums.size() ; i++){
            if(nums[i] == 0){
                countZero++;
                finalAns = max(finalAns , findMax(nums , i));
            }
        }

        if(countZero == 0) return nums.size()-1;
        else return finalAns;
    }
};

// t.c 0(n^2)
// s.c 0(1)


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCount = 0;
        int maxLen = 0;
        int i=0;
        // 0(n+n) t.c as i am vsisting two times
        for(int j=0 ; j<nums.size() ; j++){
            if(nums[j] == 0){
                zeroCount++;
            }

            while(zeroCount > 1){
                if(nums[i] == 0) zeroCount--;
                i++;
            }
            maxLen = max(maxLen , j-i);
        }

        return maxLen;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0 , j=0;
        int last_zero_idx = -1;
        int res = 0;
        
        while(j < nums.size()){
            if(nums[j] == 0){
                i = last_zero_idx + 1;
                last_zero_idx = j;
            }
            res = max(res , j-i);
            j++;
        }
        return res;
    }
};
// t.c 0(n) 
// s.c 0(1)..