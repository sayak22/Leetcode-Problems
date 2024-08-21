class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); // Initialize dp array

        // Base case: single characters require one step
        for (int i = 0; i < n; ++i)
            dp[i][i] = 1;

        // Fill in the dp array
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                dp[i][j] = len; // Initialize with worst case (printing each character separately)

                // Case 1: If s[i] == s[j], we can reuse the previous substring
                if (s[i] == s[j])
                    dp[i][j] = dp[i][j-1];
                else {
                    // Case 2: Try all possible splits and find the minimum steps
                    for (int k = i; k < j; ++k)
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }

        return dp[0][n-1]; // Minimum steps to print the entire string
    }
};
