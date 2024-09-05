class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitTillNow = 0;
        int minPrice = prices[0];

        for (int price : prices) {
            // we need to maximise the profit against the minimum price till now
            // and current price.
            minPrice = min(minPrice, price);
            maxProfitTillNow = max(maxProfitTillNow, price - minPrice);
        }

        return maxProfitTillNow;
    }
};