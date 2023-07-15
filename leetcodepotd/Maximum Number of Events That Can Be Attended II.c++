class Solution {
public: 
    // =>Firstly think if the values are not given and 
    //    question will be find the maximum number of events that the person can attend ?
    //=>In that case you will try to sort the vector 
    //   Apply some greedy method to find the maximum number events the person can attend by Sorting
    //=>Now the values are there Now think can we apply siome greedy technquie here :
    //      I guess No because a large Interval can have a very large value and evven very small too .
    //=> So it's not predicatble So we have to traverse each and every path 
    //=> Traverse every path = >Recursion 
    //=> and check whether the previous taken element end is smaller than current start and if take it and go further 
    //=> Dont want leave it (Knapsack(0/1)) problem
    //=> We have three variables 
    int Recursion(vector<vector<int>>& events , int i , int k , int prev , vector<vector<int>>& dp)
    {
        if(k==0 || i>=events.size())
        {
            return 0;
        }
        //cout<<events[i][0]<<": "<<events[i][1]<<" : "<<k<<" : "<<prev<<" : "<<endl;
        if(dp[k][prev]!=-1)
        {
            return dp[k][prev];
        }
        int a = 0, b= 0;
        if(events[i][0]>events[prev][1])
        {
            a= events[i][2]+ Recursion(events , i+1  , k-1 , i, dp);
        }
        
        b= 0+ Recursion(events , i+1 , k , prev, dp);
        
        return  dp[k][prev]= max(a, b);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        events.push_back({0,0,0}); // starting prev can be declared
        // Sort the vector because we are wanting the starting in increasing order 
        sort(events.begin() , events.end());
        //cout<<events.size()<<endl;
        vector<vector<int>> dp( k+1, vector<int>(events.size()+1,-1));
        return Recursion(events, 1, k , 0 , dp);
    }
};