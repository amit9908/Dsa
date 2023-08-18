class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        // Code here
         vector<int> ans;
         if(n == 0)return ans;
         ans.push_back(a[n-1]);
         
         int maxi = a[n-1];
         
         for(int i = n-2 ; i>=0 ; i--){
             if(a[i] >= maxi){
                 ans.push_back(a[i]);
                 maxi = a[i];
                }
         }
         
         reverse(ans.begin() , ans.end());
         return ans;
    }
};