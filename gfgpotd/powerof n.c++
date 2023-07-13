class Solution{
    public:
    //You need to complete this fucntion
    
    long long power(int n,int r)
    {
       //Your code here
       long long m =  1000000007;
       long long ans=1,b=n;
       while(r > 0){
           if(r&1){
               ans = (ans * b)%m;
           }
           b = (b*b)%m;
           r>>=1;
       }
       return ans;
       
        
    }

};
Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(LogN)