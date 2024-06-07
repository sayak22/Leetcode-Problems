class Solution {
public:
/*
::::::::::::::::::::::::::
RECCURSION + MEMORIZATION
::::::::::::::::::::::::::
*/
    // vector<int> dp;
    // int solve(vector<int>& nums, int n) {
    //     if (n <= 0)
    //         return 0;

    //     if (dp[n] != -1)
    //         return dp[n];
    //     //        max(NOT taking current element, taking current element)
    //     return dp[n] = max(solve(nums, n - 1), nums[n - 1] + solve(nums, n - 2));
    // }

    // int rob(vector<int>& nums) {
    //     dp.assign(nums.size() + 1, -1);
    //     return solve(nums, nums.size());
    // }

    int rob(vector<int>& nums) {
        int prev2=0, prev=0, curi; //prev2 represents dp[-ve index], prev represents dp[0], curri represents dp[i]

        for(int i=0;i< nums.size();i++){
            int take = nums[i] + prev2;
            int notTake = 0 + prev;
            int curi=max(take, notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};