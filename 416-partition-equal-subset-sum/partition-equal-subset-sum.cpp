class Solution {
public:
        bool canPartitionMemoized(const vector<int>& nums, int index, int targetSum, vector<vector<int>>& memo) {
        // Base cases
        if (targetSum == 0) return true; // Found a subset with the required sum
        if (targetSum < 0 || index < 0) return false; // No valid subset found

        // Check if the result is already computed and stored in memo
        if (memo[index][targetSum] != -1) return memo[index][targetSum];

        // Recursively check two possibilities:
        // 1. Including the current number in the subset
        // 2. Excluding the current number from the subset
        memo[index][targetSum] = canPartitionMemoized(nums, index - 1, targetSum - nums[index], memo) || 
                                canPartitionMemoized(nums, index - 1, targetSum, memo);
        return memo[index][targetSum];
    }

    // Main function to check if the array can be partitioned into two subsets with equal sum
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;

        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }

        // If the total sum is odd, it's not possible to partition it into two equal subsets
        if (totalSum % 2 != 0) return false;

        // Target sum for each subset is half of the total sum
        int targetSum = totalSum / 2;

        // Initialize memoization table with -1
        vector<vector<int>> memo(nums.size(), vector<int>(targetSum + 1, -1));

        // Use the helper function to check if a subset with the target sum exists using memoization
        return canPartitionMemoized(nums, nums.size() - 1, targetSum, memo);
    }
};