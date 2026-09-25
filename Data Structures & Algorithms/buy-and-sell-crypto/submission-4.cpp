class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[prices.size() - 1];
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            int test_buy = prices[i];
            for (int j = i; j < prices.size(); j++) {
                int test_sell = prices[j];
                if ((test_sell - test_buy) > max_profit) {
                    buy = test_buy;
                    sell = test_sell;
                    max_profit = sell - buy;
                } 
            }
        }
        return max_profit;
    }
};
