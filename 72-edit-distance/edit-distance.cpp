class Solution {
public:
/*:::::::::::::::: RECURSIVE APPROCH ::::::::::::
    int minDistance(string word1, string word2) {
        return helper(word1, word2, word1.size(), word2.size());
    }
    
    int helper(const string &word1, const string &word2, int m, int n) {
        // Base cases
        if (m == 0) return n; // If word1 is empty, we need n insertions
        if (n == 0) return m; // If word2 is empty, we need m deletions
        
        // If last characters match, no new operation is needed
        if (word1[m - 1] == word2[n - 1]) {
            return helper(word1, word2, m - 1, n - 1);
        }
        
        // If last characters don't match, consider all three operations
        return 1 + min({helper(word1, word2, m - 1, n),    // Deletion
                        helper(word1, word2, m, n - 1),    // Insertion
                        helper(word1, word2, m - 1, n - 1) // Substitution
                       });
    }
    */

    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // Create a 2D DP array initialized with -1 to indicate uncomputed states
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(word1, word2, m, n, dp);
    }
    
    int helper(const string &word1, const string &word2, int m, int n, vector<vector<int>> &dp) {
        // Base cases
        if (m == 0) return n; // If word1 is empty, we need n insertions
        if (n == 0) return m; // If word2 is empty, we need m deletions
        
        // Check if the result is already computed
        if (dp[m][n] != -1) return dp[m][n];
        
        // If last characters match, no new operation is needed
        if (word1[m - 1] == word2[n - 1]) {
            dp[m][n] = helper(word1, word2, m - 1, n - 1, dp);
        } else {
            // If last characters don't match, consider all three operations
            dp[m][n] = 1 + min({helper(word1, word2, m - 1, n, dp),    // Deletion
                                helper(word1, word2, m, n - 1, dp),    // Insertion
                                helper(word1, word2, m - 1, n - 1, dp) // Substitution
                               });
        }
        
        return dp[m][n];
    }
};
