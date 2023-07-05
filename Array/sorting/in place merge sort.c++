class Solution {
public:
    void mergeInPlace(vector<int>& v , int start , int end){
    int total_length = end-start+1;
    int gap = total_length/2+total_length%2;
    while(gap > 0){
        int i=start , j=start+gap;
        while(j<=end){
        if(v[i] > v[j]){
            swap(v[i],v[j]);
        }
        i++,j++;
      }
      gap = gap <= 1 ? 0 : (gap/2)+(gap%2);
    }
 }

    void mergeSort(vector<int>& v , int start , int end){
        if(start >= end) return ;
        int mid = start+(end-mid)/2;
        mergeSort(v , start , mid);
        mergeSort(v , mid+1 , end);
        mergeInPlace(v , start , end);

    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
        
    }
};