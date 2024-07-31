class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX); // Initialize DP array with large values
        dp[0] = 0; // Base case: no books require 0 height
        
        for (int i = 1; i <= n; ++i) {
            int total_width = 0; // Accumulate total width of books from j to i
            int max_height = 0; // Track maximum height of books from j to i
            for (int j = i; j > 0; --j) {
                total_width += books[j-1][0]; // Add the width of the j-th book
                if (total_width > shelfWidth) {
                    break; // Stop if the total width exceeds the shelf width
                }
                max_height = max(max_height, books[j-1][1]); // Update max height
                dp[i] = min(dp[i], dp[j-1] + max_height); // Update DP value
            }
        }
        
        return dp[n]; // Minimum height for arranging all books
    }
};
