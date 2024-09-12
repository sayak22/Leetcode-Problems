class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {

        set<int> st;
        int count = 0;
        for (char ch : allowed)
            st.insert(ch);

        for (int i = 0; i < words.size(); i++) {
            int flag = 0;
            for (int j = 0; j < words[i].size(); j++) {
                if (st.count(words[i][j]) == 0) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
                count++;
        }
        return count;
    }
};