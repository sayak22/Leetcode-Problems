class Solution {
public:
    vector<vector<int>> dp;

    /*
    ::::::::::::::::::::::::
    Memorization approach ::
    ::::::::::::::::::::::::
    */
    //    int solve(string t1, string t2, int n1, int n2) {
    //     /*if one of the strings are empty, then there is nothing to take
    //     common in the empty string, therefore we return the lcs=0*/ if (n1 ==
    //     0 or n2 == 0)
    //         return 0;

    //     if (dp[n1][n2] != -1)
    //         return dp[n1][n2];

    //     if (t1[n1 - 1] == t2[n2 - 1]) // this case denotes matching
    //     characters
    //         return dp[n1][n2] = 1 + solve(t1, t2, n1 - 1, n2 - 1);

    //     //denotes non matching characters
    //     else {
    //         //We truncate the first string, but take the entire second string
    //         int c1 = solve(t1, t2, n1 - 1, n2);
    //         //We truncate the second string, but take the entire first
    //         string. int c2 = solve(t1, t2, n1, n2 - 1);

    //         // If you look at the decision tree, we need to take the max
    //         between the two sub problems, Because it is longest common
    //         subsequence. return dp[n1][n2] = max(c1, c2);
    //     }
    // }

    /*
    ::::::::::::::::::::::::
    Top down approach ::::::
    ::::::::::::::::::::::::
    */

    int solve(string t1, string t2, int n1, int n2) {
        /*if one of the strings are empty, then there is nothing to take common
         * in the empty string, therefore we return the lcs=0*/
        if (n1 == 0 or n2 == 0)
            return 0;

        for (int i = 0; i <=n1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <=n2; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n1; i++) {
            for (int j = 1; j <= n2; j++) {
                if (t1[i - 1] == t2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n1][n2];
        
    }

    int longestCommonSubsequence(string t1, string t2) {

        int n1 = t1.length(), n2 = t2.length();
        dp.assign(n1 + 1, vector<int>(n2 + 1, -1));
        return solve(t1, t2, n1, n2);
    }
};