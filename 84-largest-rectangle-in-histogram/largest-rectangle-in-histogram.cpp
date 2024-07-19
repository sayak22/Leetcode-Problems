class Solution {
public:
/*Explanation:
1 -We use a stack to keep track of the indices of bars in increasing order of their heights.

2 -For each bar, we check whether it can extend the current rectangle or if it starts a new rectangle.

3 - If the current bar’s height is greater than or equal to the height of the bar at the top of the stack, we push its index onto the stack.

4 - Otherwise, we keep popping elements from the stack until we find a bar whose height is smaller than the current bar. For each popped element, we calculate the area of the rectangle it forms (using the popped bar’s height and the width between the current bar and the next bar in the stack).

5 - The width for the last remaining bars in the stack will be the difference between the current index and the index at the top of the stack.

6 - We update the maximum area as we go through the bars.*/

// TC: O(N) SC(N) [N is the size of the array heights]
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stack to store indices of bars
        int maxArea = 0;

        for (int i = 0; i < n; ++i) {
            // Step 1: Check if the current bar can extend the current rectangle
            while (!st.empty() && heights[i] < heights[st.top()]) {
                // Pop bars and calculate area for each
                int h = heights[st.top()]; // Height of the popped bar
                st.pop();                  // Remove the top bar from the stack

                // Width of the rectangle
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, h * width); // Update the maximum area
            }
            // Push the current bar's index onto the stack
            st.push(i);
        }

        // Step 2: Process any remaining bars in the stack
        while (!st.empty()) {
            int h = heights[st.top()]; // Height of the remaining bar
            st.pop(); // Remove the remaining bar from the stack
            int width =
                st.empty() ? n : n - st.top() - 1; // Width of the rectangle
            maxArea = max(maxArea, h * width);     // Update the maximum area
        }

        return maxArea;
    }
};
