class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int max_profit = 0;
        while (r < prices.size()) {
            max_profit = std::max(max_profit, prices[r] - prices[l]);

            if (prices[l] > prices[r]) {
                l = r;
            }
            r++;
        }
        return max_profit;
    }
};
