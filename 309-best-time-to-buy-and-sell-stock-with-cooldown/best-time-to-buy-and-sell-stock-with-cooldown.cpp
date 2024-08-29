class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sell = 0;  // Maximum profit after selling
        int hold = INT_MIN;  // Maximum profit after buying (holding)
        int prev = 0;  // Previous day's maximum profit after selling

        for (const int price : prices) {
            const int cache = sell;  // Store the current sell value
            sell = max(sell, hold + price);  // Update sell (consider selling or not)
            hold = max(hold, prev - price);  // Update hold (consider buying or not)
            prev = cache;  // Update previous day's value
        }

        return sell;  // Return the maximum profit achievable
    }
};
