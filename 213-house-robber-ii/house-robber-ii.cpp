class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];
        //        max(NOT taking current element, taking current element)
        return dp[n] = max(solve(nums, n - 1, dp), nums[n - 1] + solve(nums, n - 2, dp));
    }

    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];
        vector<int> temp1, temp2;
        for(int i=0;i<nums.size();i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=nums.size()-1) temp2.push_back(nums[i]);
        }
        vector<int> dp1(temp1.size()+1,-1);
        vector<int> dp2(temp2.size()+1,-1);
        return max(solve(temp1, temp1.size(),dp1), solve(temp2, temp2.size(),dp2));
    }
};