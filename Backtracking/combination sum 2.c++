class Solution {
public:
    
    int currSum = 0;
    void solve(vector<int>& cand, int target , vector<int>& temp , vector<vector<int>>& res , int index){
        if(currSum > target){
            return ;
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
        solve(cand , target , temp , res , index+1);
        temp.pop_back();
        currSum -= cand[index];


        while(index+1 < cand.size() && cand[index] == cand[index+1]) index++;
        solve(cand , target , temp , res , index+1);
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> res;
         vector<int> temp;
         sort(candidates.begin() , candidates.end());
         solve(candidates , target , temp , res , 0);
         return res;
    }
};