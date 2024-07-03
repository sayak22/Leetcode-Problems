class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int diff = 0; diff < n; diff++) {
            for (int i = 0, j = i + diff; j < n; i++, j++) {
                if (i == j)
                    dp[i][j] = 1;
                else if (diff == 1)
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0;
                else {
                    if (s[i] == s[j] and dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                    }
                }
                if (dp[i][j])
                    count++;
            }
        }
        return count;
    }
};