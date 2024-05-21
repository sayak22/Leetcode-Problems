class Solution {
public:
    vector<int> dp;
    int solve(int n){
         if (n==1 || n==0) return 1;
        else if (dp[n]!=-1) return dp[n];
        else return dp[n]=solve(n-1) + solve(n-2);
    }
    int climbStairs(int n) {
        dp.resize(n+1);
        dp.assign(n+1,-1);
        return solve(n);
    }
};