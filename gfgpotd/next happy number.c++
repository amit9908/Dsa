class Solution{
public:
    bool isHappy(int n){
        if(n == 1 || n == 7) return true;
        int sum = n , curr = n;
        
        while(sum > 9){
            sum = 0;
            while(curr > 0){
                int d = curr%10;
                sum += d*d;
                curr/=10;
            }
            if(sum == 1){
                return 1;
            }else{
                curr = sum;
            }
            
            
        }
        if(curr == 7) return 1;
        else return 0;
        
        
    }
    int nextHappy(int N){
        // code here
        int next = N+1;
        int res = 0;
        while(true){
            if(isHappy(next)){
                res = next;
                break;
            }else{
                next = next+1;
            }
        }
        
        return res;
    }
};