class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> st;
        int points = 0;
        if (x > y) {
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'b' and !st.empty() and st.back() == 'a') {
                    points += x;
                    st.pop_back();
                } else
                    st.push_back(s[i]);
            }

            vector<char> new_st;
            for (char it : st) {
                if (it == 'a' and !new_st.empty() and new_st.back() == 'b') {
                    points += y;
                    new_st.pop_back();
                } else
                    new_st.push_back(it);
            }

        } else {
                for (int i = 0; i < s.length(); i++) {
                if (s[i] == 'a' and !st.empty() and st.back() == 'b') {
                    points += y;
                    st.pop_back();
                } else
                    st.push_back(s[i]);
            }

            vector<char> new_st;
            for (char it : st) {
                if (it == 'b' and !new_st.empty() and new_st.back() == 'a') {
                    points += x;
                    new_st.pop_back();
                } else
                    new_st.push_back(it);
            }

        }
        return points;
    }
};