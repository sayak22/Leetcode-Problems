class Solution {
public:
    // Recursive function with memoization
    // int solveMemo(vector<int>& coins, int amount, int index, vector<vector<int>>& dp) {
    //     // Base cases
    //     if (amount == 0) {
    //         return 1; // Found a valid combination
    //     }
    //     if (amount < 0 || index >= coins.size()) {
    //         return 0; // Invalid combination
    //     }
        
    //     // Check if this state is already computed
    //     if (dp[index][amount] != -1) {
    //         return dp[index][amount];
    //     }
        
    //     // Two choices: take the current coin or skip it
    //     int take = solveMemo(coins, amount - coins[index], index, dp);
    //     int dontTake = solveMemo(coins, amount, index + 1, dp);
        
    //     // Update the memoization table
    //     dp[index][amount] = take + dontTake;
        
    //     return dp[index][amount];
    // }
    
    // int change(int amount, vector<int>& coins) {
    //     // Initialize memoization table
    //     vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
    //     return solveMemo(coins, amount, 0, dp);
    // }

// :::::: tabulation :::::::
     int change(int amount, vector<int>& coins) {
        // Initialize a 2D DP array with dimensions (coins.size() + 1) x (amount + 1)
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        int n = coins.size();

        // Base case: If the amount is zero, there's one way (empty combination)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Fill up the DP array
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                // Two choices: either take the current coin or skip it
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The result is stored in dp[n][amount]
        return dp[n][amount];
    }
};