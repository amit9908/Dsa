bool comp(pair<int,int>a,pair<int,int>b){
    //fraction ke according change karna hai
    double f=((1.0)*a.first)/a.second;
    double s=((1.0)*b.first)/b.second;
    return f>s;
}
class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            vec.push_back({arr[i].value,arr[i].weight});
        }
        sort(vec.begin(),vec.end(),comp);
        double ans=0;
        for(int i=0;i<n;i++){
           
            if(vec[i].second<=W){
                ans+=vec[i].first;
                
                W-=vec[i].second;
            }
            else{
                double frac=((1.0)*vec[i].first)/vec[i].second;
                ans+=frac*W;
                
                W=0;
            }
        }
        return ans;
        
    }
        
};