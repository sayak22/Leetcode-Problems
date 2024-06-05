class Solution {
public:
    unordered_set<string> st;
    int dp[301];
    bool solve(int index, string s) {

        if (index >= s.length())
            return true;

        if (st.find(s) != st.end())
            return true;

        if (dp[index] != -1)
            return dp[index]==1;

        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(index, i);
            if (st.find(word) != st.end() and solve(index + i, s))
                {dp[index] = 1; return dp[index]==1;}
        }
        dp[index] = 0;
        return dp[index]==1;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        for (string& it : wordDict) {
            st.insert(it);
        }
        return solve(0, s);
    }
};