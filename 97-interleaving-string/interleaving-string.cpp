class Solution {
public:
/* ::::::::::::: RECURSIVE SOLUTION ::::::::::::::
    bool isInterleave(string s1, string s2, string s3) {
        return helper(s1, s2, s3, 0, 0, 0);
    }
    
    bool helper(const string& s1, const string& s2, const string& s3, int i, int j, int k) {
        // Base case: If we've reached the end of all strings
        if (i == s1.size() && j == s2.size() && k == s3.size()) {
            return true;
        }
        
        // Check if s1[i] matches s3[k]
        bool match1 = (i < s1.size() && s1[i] == s3[k]) && helper(s1, s2, s3, i + 1, j, k + 1);
        
        // Check if s2[j] matches s3[k]
        bool match2 = (j < s2.size() && s2[j] == s3[k]) && helper(s1, s2, s3, i, j + 1, k + 1);
        
        // Either s1[i] or s2[j] should match s3[k]
        return match1 || match2;
    }
*/
// :::::::::: MEMORISATION ::::::::::::
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size()) return false;  // If lengths don't add up, return false

    // Initialize dp table with -1 (indicating uncomputed state)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return helper(s1, s2, s3, 0, 0, dp);
}

bool helper(const string& s1, const string& s2, const string& s3, int i, int j, vector<vector<int>>& dp) {
    // If we've reached the end of s1 and s2, check if we've also reached the end of s3
    if (i == s1.size() && j == s2.size()) {
        return true;
    }

    // If this state has already been computed, return the stored result
    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    bool match1 = false, match2 = false;
    int k = i + j;  // Calculate index k for s3 based on i and j

    // Check if s1[i] matches s3[k] and recursively check further
    match1 = (i < s1.size() && s1[i] == s3[k]) and helper(s1, s2, s3, i + 1, j, dp);


    // Check if s2[j] matches s3[k] and recursively check further
    match2 =  (j < s2.size() && s2[j] == s3[k]) and helper(s1, s2, s3, i, j + 1, dp);


    // Store the result in dp table before returning
    dp[i][j] = match1 || match2;
    return dp[i][j];
}


};
