class Solution {
public:
    typedef long long ll;
    bool possible(vector<int>& batteries , ll mid_minutes , int n){
        ll target_minutes = n*mid_minutes;
        
        ll sum = 0;
        for(int i=0 ; i<batteries.size() ; i++){
            target_minutes -= min((ll)batteries[i] , mid_minutes);
            if( target_minutes <= 0)return true;
        }
        return false;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l = *min_element(begin(batteries) , end(batteries));

        ll sum_total_minutes = 0;
        for(auto &mints  : batteries){
            sum_total_minutes += mints;
        } 

        ll r = sum_total_minutes/n;

        ll result = 0;

        while( l <= r){
            ll mid_minutes = l + (r-l)/2;
            if(possible(batteries,mid_minutes,n)){
                result = mid_minutes;
                l = mid_minutes+1;
            }else{
                r = mid_minutes-1;
            }
        }
        return result;
    }
};