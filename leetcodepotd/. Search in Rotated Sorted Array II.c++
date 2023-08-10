class Solution {
public:
    int solvePivot(vector<int>& nums , int s , int e){
      while(s < e && nums[s] == nums[s+1]){
          s++;
        }
      while(s < e && nums[e] == nums[e-1]){
          e--;
      }
      
      while(s < e){
          int mid = s + (e-s)/2;
          if(nums[mid] > nums[e]){
              s = mid+1;
          }else{
              e = mid;
           }
      }
      
      return e;

    }
    bool binarySearch(vector<int> nums , int s , int e ,int target){
        int mid = s+(e-s)/2;
        while(s<=e){
            if(nums[mid] == target){
                return true;
            }
            
            else if(nums[mid] < target){
                s = mid+1;
            }else{
                e = mid-1;
            }
            mid = s+(e-s)/2;
        }
        return false; 
    }

    bool search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size()-1;
        int pivot = solvePivot(nums , s , e);
        
        if(binarySearch(nums , 0 , pivot-1 , target)) return true;
        return binarySearch(nums , pivot , e , target) ;

    }
};