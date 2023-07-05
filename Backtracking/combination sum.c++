class Solution {
public:

       int currSum = 0;
   
       void solve(vector<vector<int>>& res , vector<int>& temp ,vector<int>& cand, int target , int index){
       if(currSum > target){
           return;
       }

       if(index == cand.size()){
           if(currSum == target){
               res.push_back(temp);
                return;
           }
                  
           return;
       }
        
        currSum += cand[index];
        temp.push_back(cand[index]);
        solve(res , temp ,cand , target , index);
        temp.pop_back();
        currSum -= cand[index];


        solve(res , temp , cand , target , index+1);

        
   }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
          vector<vector<int>> res;
          vector<int> temp;
          solve(res , temp , candidates , target , 0);
          return res;
    }
};