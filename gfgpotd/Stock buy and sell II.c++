class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &prices) {
        // code here
        int sum=0;
        
        for(int i=1; i<n ; i++){
            int diff = prices[i] - prices[i-1];
            int profit=0;
            profit = max(profit , diff);
            sum += profit;
        }
        return sum;
    }
};

// t.c 0(n)
// s.c 0(1)