class Solution {
public:
/* RECCURSION + MEMORISATION
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
    */
    /*Tabulation
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
    */
    int climbStairs(int n) {
        if(n==0 || n==1) return 1;
        int a=1, b=1;
        for(int i=2; i<=n; i++)
        {
            int temp=a+b;
            a=b;
            b=temp;
        }
        return b;
    }
};