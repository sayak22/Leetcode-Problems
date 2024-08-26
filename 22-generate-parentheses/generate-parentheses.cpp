class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        backtrack(ans, n, 0, 0, "");
        return ans;
    }

    void backtrack(vector<string> &ans, int n, int open, int close, string currentString){

        //base case
        if(currentString.size()==2*n){ // since n is number of pairs of parentheses
            ans.push_back(currentString);
            return;
        }

        if(open<n) // inserts "("  
            backtrack(ans, n, open+1, close, currentString+"(");
                
        if(close<open) // inserts ")"
            backtrack(ans, n, open, close+1, currentString+")");
        
    }

};