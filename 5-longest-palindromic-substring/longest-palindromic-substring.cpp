class Solution {
public:
    string longestPalindrome(string s) {
        int maxLength = 0; // to keep track of the longest palindrome word
        string ans = "";   // to store the answer
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), 0));
        // this is a special type of problem where we are populating diagonals
        // only above i=0, j=0, i.e for indices j>i
        for (int diff = 0; diff < s.length();
             diff++) { // each diagonal represents diff between i and j.

            // i represents starting index and j represents ending index of the
            // string.
            for (int i = 0, j = i + diff; j < s.length();
                 i++, j++) { // we are incrementing both i and j to access all
                             // the diagonal elements eg. {{0,0), (1,1).....},
                             // {(0,1), (1,2), (2,3),...}

                if (i == j) // if there is only one character in the string then
                            // length of palindrome =1
                    dp[i][j] = 1;

                else if (diff == 1) // diff=1 i.e there are 2 chars in the
                                    // string ,i.e if s[i]==s[j] then string is
                                    // palindrome and length=2
                    dp[i][j] = (s[i] == s[j]) ? 2 : 0;

                else {
                    // if the diff is more than 2 then we check s[i]==s[j] and
                    // whether the inner string is palindrome or not,i.e
                    // dp[i+1][j-1] != 0 or not, if it is 0 then the inner
                    // string is not palindrome.
                    if (s[i] == s[j] and dp[i + 1][j - 1])
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                // if current string is palindrome, i.e dp[i][j]!=0, then we can
                // check if it is more than the maxLength recorded till now, and
                // then if that is the case then update the maxLength and update
                // ans string.
                if (dp[i][j] and j - i + 1 > maxLength) {
                    maxLength = j - i + 1;
                    ans = s.substr(i, maxLength);
                }
            }
        }
        return ans;
    }
};