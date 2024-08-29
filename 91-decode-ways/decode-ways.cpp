class Solution {
public:
    // RECCURSION AND MEMORISATION
    int solve(int i, string s, vector<int>& dp) {
        // base cases

        // When we have gone out of bounds of the string, it means
        // that we have decoded the entire string, and therefore
        // we return 1
        if (i >= s.size())
            return 1;

        // We neither can decode 0 individually, neither with
        // another character like 06, therefore return 0 whenever
        // we encounter 0
        else if (s[i] == '0')
            return 0;

        // when we reach the last character that means there can
        // only be one way to decode one character, therefore
        // return 1.
        else if (i == s.size() - 1)
            return 1;
        // body
        else if (dp[i] != -1)
            return dp[i]; // check if computed earlier or not

        else if (s[i] == '1' or (s[i] == '2' and s[i + 1] <= '6'))
            return dp[i] =
                       solve(i + 1, s, dp) +
                       solve(i + 2, s,
                             dp); // if the i and i+1 th number is between 10 to
                                  // 26 then this is executed, i.e, decode
                                  // taking i th character, or taking i and i+1
                                  // th character together, and decode the rest
        else
            return dp[i] = solve(i + 1, s, dp); // else just take a single
                                                // character and decode the rest
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(0, s, dp);
    }
};