class Solution {
public:
    vector<int> dp;
    int solve(vector<int>& nums, int n) {
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        //        max(NOT taking current element, taking current element)
        return dp[n] = max(solve(nums, n - 1), nums[n - 1] + solve(nums, n - 2));
    }

    int rob(vector<int>& nums) {
        dp.assign(nums.size() + 1, -1);
        return solve(nums, nums.size());
    }
};