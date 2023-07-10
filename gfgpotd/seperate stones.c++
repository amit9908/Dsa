class Solution {
  public:
    int separateStones(int N, int k, vector<int> &a) {
        // code here
        
        int zero = 0 , ones = 0 , cnt=0;

        for(int i=0 ; i<N ; i++){
            if(a[i] == 0) zero++;
            else ones++;
        }
        
        if(zero != 0){
            if(zero%k == 0) cnt += zero/k;
            else cnt += (zero/k) + 1;
        }
         
        if(ones != 0){
             if(ones%k == 0) cnt += ones/k;
             else cnt += (ones/k) + 1;
        }
       
        
        return cnt;
    }
};