class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int countFive = 0 ,countTen = 0 ,countTwenty = 0;
        for(int i=0 ; i<N ; i++){
            if(bills[i] > 5){
                int val = bills[i] - 5;
                while(val > 0){
                    if(val >= 20 && countTwenty > 0){
                        val = val - 20;
                        countTwenty --;
                    }else if(val >= 10 && countTen > 0){
                        val = val - 10;
                        countTen--;
                    }else if(val >= 5 && countFive > 0){
                        val = val - 5;
                        countFive--;
                    }else{
                        return false;
                    }
                }
            }
            
            if(bills[i] == 5) countFive++;
            else if(bills[i] == 10) countTen++;
            else countTwenty++;
        }
        return true;
        
        
    }
};