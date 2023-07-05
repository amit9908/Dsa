class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        if(k<=1) return 0;
        long long product = 1 , left = 0 ,right = 0 ,count=0;
        while(right < n){
            product = product *a[right];
            while(product >= k){
                product /= a[left];
                left++;
            }
            count += right-left+1;
            right++;
        }
        
        return count;
    }
};