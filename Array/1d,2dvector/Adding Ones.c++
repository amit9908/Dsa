
class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here
        vector<int>to_update(n,0);
        
        for(int i=0 ; i<k ; i++){
            to_update[updates[i]-1]++;
        }
        
        int totalCounts = 0;
        for(int i=0 ; i<n ; i++){
            totalCounts += to_update[i];
            a[i] += totalCounts;
        }
    }
};


class Solution{
    public:
    void update(int a[], int n, int updates[], int k)
    {
        // Your code goes here
        // vector<int>to_update(n,0);
        
        for(int i=0 ; i<k ; i++){
            a[updates[i]-1]++;
        }
        
        
        for(int i=1 ; i<n ; i++){
            
            a[i] += a[i-1];
        }
    }
};