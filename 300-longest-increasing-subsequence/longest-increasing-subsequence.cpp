class Solution {
public:

    int lis(vector<int>& nums, int i, int prevIndex, vector<vector<int>> & dp){
        if(i==nums.size()) return 0;

        if( dp[i][prevIndex+1] != -1) return dp [i][prevIndex+1];

        //NOT TAKE
        int len = 0 + lis(nums, i+1, prevIndex, dp);

        //take
        if( prevIndex==-1 or nums[i] > nums[prevIndex]) 
        len= max(len, 1 + lis(nums, i+1, i, dp));  
        
        return dp[i][prevIndex+1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return lis(nums,0, -1, dp);
    }
};