class Solution {
  public:
    int minimum_difference(int n, vector<string> &a) {
        // Code here.
        int ans = INT_MAX;
        int sn = a[0].size();
        
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n && i!=j ; j++){
                int temp = 0;
                for(int k=0 ; k<sn ; k++){
                    temp += abs(a[i][k] - a[j][k]);
                }
                ans = min(ans , temp);
            }
        }
        return ans;
    }
};