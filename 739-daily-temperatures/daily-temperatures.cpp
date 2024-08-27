class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st; // stack stores indexes so that we can count the days by taking the diff. of indexes
        vector<int> ans(temperatures.size(), 0);

        // Traverse the array from right to left
        for (int i = temperatures.size() - 1; i >= 0; i--) {
            // Pop elements from the stack until we find a warmer day
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }

            // If there's a warmer day, calculate the difference in days
            if (!st.empty()) {
                ans[i] = st.top() - i;
            }

            // Push the current index onto the stack
            st.push(i);
        }

        return ans;
    }
};
