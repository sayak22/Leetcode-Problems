class Solution {
public:
    string reverseParentheses(string s) {
        /*
        In this we are storing the indexes of the starting parenthesis '(' and
        whenever we encounter a ')' we are reversing the string inside the last
        '(' and current ')'
        */
        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                int start = st.top() + 1; // since st.top() gives index of last '(' encountered, the word will start from the next index
                reverse(s.begin() + start, s.begin() + i); // reverse(starting pointer, ending pointer)
                st.pop();
            }
        }

        string ans = "";
        // remove all the parenthesis and store the string in the ans variable
        // and return it
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' and s[i] != ')')
                ans += s[i];
        }
        return ans;
    }
};