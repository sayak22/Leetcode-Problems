class Solution {
public:
    // TC: O(N) SC:O(N) [when k == n]
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result; // To store the maximums
        deque<int> dq; // Double-ended queue that stores indices of potential
                       // maximums for the current window in decreasing order.

        for (int i = 0; i < nums.size(); ++i) {
            // Remove indices that are out of the current window (if i=6, then
            // begining of the window = 6-3+1 = 4) if an index less than 4 is
            // present in the dequeue it must be popped, as it is not in the current window.
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // Remove indices of smaller elements from the back to keep dq in descencding order.
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            // Add the current index to the deque
            dq.push_back(i);

            // If we've processed at least k elements, add the maximum to the result
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }

        return result;
    }
};
