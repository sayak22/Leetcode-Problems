class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitTillNow = 0;
        int maxPrice = prices[0], minPrice = prices[0];

        for (int price : prices) {
            if (price < minPrice) {
                minPrice = price;
                maxPrice = price;
            }
            if (price > maxPrice) {
                maxPrice = price;
                maxProfitTillNow = max(maxProfitTillNow, maxPrice - minPrice);
            }
        }

        return maxProfitTillNow;
    }
};