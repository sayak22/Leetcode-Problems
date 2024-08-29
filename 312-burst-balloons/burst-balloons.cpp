class Solution {
public:
/* ::::::::::: RECURSIVE APPROACH :::::::::::  
    int maxCoins(vector<int>& nums) {
        // Add boundary balloons with value 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        // Initialize a recursive function to find maximum coins
        return burst(nums, 0, n - 1);
    }
    
    int burst(vector<int>& nums, int left, int right) {
        // Base case: no balloons left in the subarray
        if (left + 1 == right) {
            return 0;
        }
        
        int maxCoins = 0;
        // Try all possible last balloons within the subarray
        for (int i = left + 1; i < right; ++i) {
            // Calculate coins obtained by bursting the last balloon
            int coins = nums[left] * nums[i] * nums[right];
            // Recursively solve the subproblems for the remaining balloons
            coins += burst(nums, left, i) + burst(nums, i, right);
            // Update the maximum coins for this subinterval
            maxCoins = max(maxCoins, coins);
        }
        
        return maxCoins;
    }
*/

    int maxCoins(vector<int>& nums) {
        // Add boundary balloons with value 1
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        
        // Initialize a memoization table
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Call the recursive function with memoization
        return burst(nums, 0, n - 1, dp);
    }
    
    int burst(vector<int>& nums, int left, int right, vector<vector<int>>& dp) {
        // Base case: no balloons left in the subarray
        if (left + 1 == right) {
            return 0;
        }
        
        // Check if this state is already computed
        if (dp[left][right] != -1) {
            return dp[left][right];
        }
        
        int maxCoins = 0;
        // Try all possible last balloons within the subarray
        for (int i = left + 1; i < right; ++i) {
            // Calculate coins obtained by bursting the last balloon
            int coins = nums[left] * nums[i] * nums[right];
            // Recursively solve the subproblems for the remaining balloons
            coins += burst(nums, left, i, dp) + burst(nums, i, right, dp);
            // Update the maximum coins for this subinterval
            maxCoins = max(maxCoins, coins);
        }
        
        // Store the result in the memoization table
        dp[left][right] = maxCoins;
        return maxCoins;
    }

};
