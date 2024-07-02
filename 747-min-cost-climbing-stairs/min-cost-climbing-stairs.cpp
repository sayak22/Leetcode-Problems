class Solution {
public:
    int helper(vector<int>& cost, int i, vector<int>& dp) {
        if (i >= cost.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return cost[i] + min(dp[i + 1] = helper(cost, i + 1, dp),
                             dp[i + 2] = helper(cost, i + 2, dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size() + 2, -1);
        return min(helper(cost, 0, dp), helper(cost, 1, dp));
    }
};