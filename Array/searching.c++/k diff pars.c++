// class Solution {
// public:
//     int findPairs(vector<int>& nums, int k) {
//         sort(nums.begin() , nums.end());
//         int i=0;
//         int j=1;
//         set<pair<int,int>> ans;

//         while(j<nums.size()){
//             int diff = nums[j] - nums[i];
//             if(diff == k){
//                 ans.insert({nums[i] ,nums[j]});
//                 ++i;++j;
//             }
//             else if (diff > k){
//                 i++;
//             }else {
//                 j++;
//             }
//             if(i == j) j++;
        
//         }

//         return ans.size();

//     }
// };


class Solution {
public:
   
   bool binarySearch(vector<int> nums , int s ,int e , int target){
       int mid = s+(e-s)/2;
       while(s<=e){
           if(nums[mid] == target){
               return true;
           }

           if(nums[mid] < target){
               s = mid+1;
           }else{
               e = mid-1;
           }
            mid = s+(e-s)/2;
       }
       return false;
   }
     
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>> ans;
        sort(nums.begin() , nums.end());
         
         for(int i=0 ; i<nums.size() ; i++){
          int target = k + nums[i];
          if(binarySearch(nums , i+1 , nums.size()-1 , target)){
            ans.insert({nums[i] , target});
          }
           
        }
         
        return ans.size();

    }
};