class Solution {
  public:
    int setBits(int n) {
        // Write Your Code here
        int count=0;
        while(n != 0){
            if(n%2 == 1) count++;
            n /= 2;
        }
        return count;
        
    }
};