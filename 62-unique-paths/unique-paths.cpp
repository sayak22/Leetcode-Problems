class Solution {
public:
    /*
    ::::::::::::::::::: RECCURSION AND MEMORISATION :::::::::::::::::
    */
    // vector<vector<int>> dp;
    // int solve(int i, int j, int m, int n) {
    //     if (i == m - 1 && j == n - 1)
    //         return 1;
    //     else if (i >= m || j >= n)
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     else
    //         return dp[i][j] = solve(i + 1, j, m, n) + solve(i, j + 1, m, n);
    // }

    // int uniquePaths(int m, int n) {
    //     dp.assign(m + 1, vector<int>(n + 1, -1));
    //     return solve(0, 0, m, n);
    // }

    /*
    ::::::::::::::::::: COMBINATRICS :::::::::::::::::
    */
    int uniquePaths(int m, int n) {
        int N = m + n - 2;
        // since total right moves = n-1  and total down moves = m-1, we take the sum of them.
        int r = n - 1 ;// or r = n-1 (both will give same answers)
                /*
                Explaination: if out of the total no. of moves we take all the
                right moves in any order then there is only one way for all the
                down moves to order themselves. and vice versa, therefore,
                taking m-1 or n-1 as r will give the same answer.
                */
        double ans = 1;
        for (int i = 1; i <= r; i++) 
            ans = ans * (N - r + i) / i;
        
        return (int)ans;
    }
};