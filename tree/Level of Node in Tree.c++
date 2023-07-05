class Solution {
  public:
    long long findLevel(long long N) {
        // code here
        long long sum = 1;
        long long prev = 1;
        long long level = 1;
        while(sum < N){
            level++;
            sum += (level*prev);
            prev*=level;
        }
        
        return level;
    }
};
