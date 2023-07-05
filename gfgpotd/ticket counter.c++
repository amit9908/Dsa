// t.c O(n) s.c O(1)
class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        
        int i=1, j=N , ans=0;
        bool direction = true;
        while(i <= j){
            if(direction == true){
                 ans = j;
                 i+=K;
                 direction = false;
            }else{
                ans = i;
                j -= K;
                direction = true;
            }
           
            
        }
        return ans;
    }
};

// t.c O(1) s.c O(1)
class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        int step = N/K;
        int left = step/2;
        int right = left;
        if(step%2 == 1) left++;
        int i = left*K;
        int j = N+1-K*right;
        if(step%2 == 1){
            if(N%K == 0) return i;
            return i+1;
        }
        if(N%K == 0)return j;
        return j-1;
        
    }
};
