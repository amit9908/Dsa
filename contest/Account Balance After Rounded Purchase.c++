class Solution {
public:
    int accountBalanceAfterPurchase(int p) {
        double roundedPurchase = std::round((double)p / 10.0) * 10.0;
        int balance = 100 - static_cast<int>(roundedPurchase);
        return balance;
    }
};