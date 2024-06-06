class Solution {
public:
    unordered_set<string> st;
    int dp[301]; // we are taking int dp array, as we cannot store null value in
                 // boolean array as we set -1 in int array as null value.
                 // Therefore using int dp array, with 1 as true, and false as 0
    bool solve(int index, string s) {

        if (index >= s.length())
            return true;

        if (st.find(s) !=
            st.end()) // if the whole string is found int the set then we can
                      // directly return true without any further operations.
            return true;

        if (dp[index] != -1)
            return dp[index] == 1;

        //we iterate from 
        for (int i = 1; i <= s.length(); i++) {
            string word = s.substr(index, i);
            if (st.find(word) != st.end() and solve(index + i, s)) {
                dp[index] = 1; // this means that till that position everything is okay, i.e words can be found out in the dictionary
                return dp[index] == 1; // converting int into bool and returning

            }
        }
        dp[index] = 0;
        return dp[index] == 1;// convertion int into bool and returning
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        for (string& it : wordDict) {
            st.insert(it); // set has easier fining capabilities therefore
                           // converting the vector into set
        }
        return solve(0, s);
    }
};