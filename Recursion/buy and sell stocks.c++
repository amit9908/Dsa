class Solution {
public:
    void maxiProfitFinder(vector<int>& prices, int index, int& minPrice, int& maxiProfit) {
        if (index == prices.size()) {
            return;
        }
        
        if (prices[index] < minPrice) {
            minPrice = prices[index];
        }
        
        int todayProfit = prices[index] - minPrice;     
           
        if (todayProfit > maxiProfit) {
            maxiProfit = todayProfit;
        }
        
        maxiProfitFinder(prices, index + 1, minPrice, maxiProfit);
    }
    
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxiProfit = 0;

        maxiProfitFinder(prices, 0, minPrice, maxiProfit);
        
        return maxiProfit;
    }
};
