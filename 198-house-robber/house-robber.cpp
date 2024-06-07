class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n) {
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        // NOT taking current index loot
        int loot = solve(nums, n - 1);

        // Taking current index loot and comparing it with the not taken amount
        // and taking maximum.
        loot = max(loot, nums[n - 1] + solve(nums, n - 2));

        return dp[n] = loot;
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(nums, nums.size());
    }
};