class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0;
        string ans="";
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        for (int diff = 0; diff < s.length(); diff++) {
            for (int i = 0, j = i + diff; j < s.length(); i++, j++) {
                if (i == j)
                    dp[i][j] = 1;

                else if (diff == 1)
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;

                else {
                    if (s[i] == s[j] and dp[i + 1][j - 1])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                if (dp[i] [j] and j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    ans = s.substr(i, maxLength);
                }
            }
        }
        return ans;
    }
};