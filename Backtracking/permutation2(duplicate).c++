class Solution {
public:
   
    void solve(vector<int>& x , vector<vector<int>>& ans  , int index){
    if(index >= x.size()){
        ans.push_back(x);
    }
    
    
    unordered_set<int> s;
    for(int j=index ; j<x.size() ; j++){
        if(s.find(x[j]) != s.end()) continue;
        s.insert(x[j]);
        
        swap(x[index] , x[j]);
        solve(x , ans , index+1);
        swap(x[index] , x[j]);
    
    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums , ans , 0);
        return ans;
    }
};