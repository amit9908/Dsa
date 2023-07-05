


//class Solution {
public:
   
   int solve(vector<int>& num , int i , int j){
       if(i > j) return 0;
       if(i == j) return num[i];
        
        int opt1 = num[i] + min(solve(num,i+2 , j) ,solve(num ,i+1 , j-1));
        int opt2 = num[j] + min(solve(num ,i ,j-2) , solve(num , i+1 ,j-1));

    return max(opt1 , opt2);

   }
    
    //bool PredictTheWinner(vector<int>& nums) {
        int j = nums.size() - 1;
        int player1 = solve(nums ,  0 , j);
        int totalscore = 0;
        for(int i=0 ; i<nums.size() ; i++){
            totalscore += nums[i];
        }

        int player2 = totalscore - player1;
        if(player1 >= player2) return true;
        else return false;
        
    }
};