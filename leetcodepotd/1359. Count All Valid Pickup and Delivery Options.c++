class Solution {
public:
    int countOrders(int n) {
        int M = 1e9 + 7;
        if(n == 1) return 1;
        
        long long res = 1;
        for(int i=2 ; i <= n ; i++){
            int spaces = (i-1)*2+1;
            int curr_pos = spaces*(spaces+1)/2;
            res *= curr_pos;
            res = res%M;
        }
        return res;
    }
};