class Solution {
public:
vector<int> dp;
    //RECCURSION AND MEMORISATION
    int solve(int i, string s){
        //base cases
        if(i >= s.size()) return 1;
        else if(s[i]=='0') return 0;
        else if(i==s.size()-1) return 1;
        //body
        else if(dp[i]!=-1) return dp[i];
        else if(s[i]=='1' or (s[i]=='2' and s[i+1]<='6'))
        return dp[i]= solve(i+1,s) + solve(i+2,s);
        else
        return dp[i]=solve(i+1,s);

    }

    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(),-1);
          return solve(0,s);
    }
};