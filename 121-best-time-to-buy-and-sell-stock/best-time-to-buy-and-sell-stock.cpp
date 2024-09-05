class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfitTillNow = 0;
        int minPrice = prices[0];

        for (int price : prices) {
            minPrice = min(minPrice, price);
            // if (price > maxPrice) {
            // maxPrice = price;
            maxProfitTillNow = max(maxProfitTillNow, price - minPrice);
            // }
        }

        return maxProfitTillNow;
    }
};