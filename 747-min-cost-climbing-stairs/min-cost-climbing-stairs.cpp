
class Solution {
public:
    /*
    ::::::::::::::::::::::::::::
    Recursion + memorisation :::
    ::::::::::::::::::::::::::::
    */
    int helper(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return cost[i] + min(dp[i + 1] = helper(cost, i + 1, dp),
                             dp[i + 2] = helper(cost, i + 2, dp)); // adding the current cost to the value of cost of the remaining array
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2, -1);
        return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }

    /*
    ::::::::::::::
    Tabulation :::
    ::::::::::::::
    */
    // int minCostClimbingStairs(vector<int>& cost) {
    //     // int n = cost.size();
    //     vector<int> dp(cost.size() + 1, 0);

    //     for (int i = 2; i <= cost.size(); ++i) {
    //         dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
    //     }
    //     return dp[cost.size()];
    // }
};