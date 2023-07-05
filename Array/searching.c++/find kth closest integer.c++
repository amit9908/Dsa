
class Solution {
public:
   
   int lowerBound(vector<int>nums ,int x){
       int s = 0;
       int e = nums.size()-1;
       int mid = s+(e-s)/2;
       int ans = e;

       while(s<=e){
           if(nums[mid]>=x){
               ans = mid;
               e = mid-1;
           }
           if(x>nums[mid]){
               s = mid+1;
           }else{
               e = mid-1;
           }

           mid = s+(e-s)/2;
       }
       return ans;
   }
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        // int low = 0 ; 
        // int high = nums.size()-1;
        // vector<int> ans;
        // // int mid = low+(high-low)/2;

        // while(high-low >= k){
        //     if(x-nums[low] > nums[high]-x){
        //         low++;
        //     }else{
        //         high--;
        //     }

        // }

        // for(int i=low ; i<=high ; i++){
        //     ans.push_back(nums[i]);
        // }

        // return ans;


        int high = lowerBound(nums , x);
        int low = high-1;

        while(k--){
            if(low<0){
                high++;
            }
            else if(high >= nums.size()){
                low--;
            }
            else if(x-nums[low] > nums[high]-x){
                high++;
            }else{
                low--;
            }
        }
        
        return vector<int>(nums.begin()+low+1,nums.begin()+high);
    }
};