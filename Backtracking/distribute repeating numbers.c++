class Solution {
public:

    bool solve(vector<int>& quantity , map<int,int> &cnt , int index){
           if(index >= quantity.size()){
            return true;
           }

        for(auto it=cnt.begin() ; it != cnt.end() ; it++){
            if(it->second >= quantity[index]){
                cnt[it->first] = cnt[it->first] - quantity[index];
                bool next = solve(quantity , cnt , index+1);
               if(next == true){
                    return true;
                }
                cnt[it->first] = cnt[it->first] + quantity[index];
            }
        }
        return false;
    }
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        map<int,int> cnt;
        for(int i=0 ; i<nums.size() ; i++){
            cnt[nums[i]]++;
        } 
        sort(quantity.begin() ,quantity.end() ,greater<int>());
        bool ans = solve(quantity , cnt , 0);
        return ans; 
    }
};

