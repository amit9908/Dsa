class Solution {
public:

    void solve(int i , int k , int n , vector<int>& jobs , vector<int>& work , int ans , int &res){
        if(i == n){
            ans = *max_element(work.begin() , work.end());
            res = min(res ,ans);
            return;
        }
        
        if(*max_element(work.begin() , work.end()) >= res) return;
        
        for(int j=0 ; j<k ; j++){
            if(j>0 && work[j] >= work[j-1]) continue;
            work[j] += jobs[i];
            solve(i+1 , k  , n , jobs , work  ,ans , res);
            work[j] -= jobs[i];
        }
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin() , jobs.end() , greater<int>());
        int n = jobs.size();
        if(k == n) return jobs[0];

        vector<int> work(k,0);
        int ans = 0;
        int finalAns = INT_MAX;
        int index = 0;
        solve(index , k  , n , jobs ,work , ans , finalAns);
        return finalAns;
    }
};