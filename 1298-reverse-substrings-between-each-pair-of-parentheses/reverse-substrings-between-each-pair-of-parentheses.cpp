class Solution {
public:
    string reverseParentheses(string s) {

        stack<int> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                int start = st.top();
                reverse(s.begin() + start + 1, s.begin() + i);
                st.pop();
            }
        }

        string ans = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '(' and s[i] != ')')
                ans += s[i];
        }
        return ans;
    }
};