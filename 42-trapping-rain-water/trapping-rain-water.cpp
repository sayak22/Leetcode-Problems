class Solution {
public:

  // TC: O(N) SC:O(N) n is the number of blocks whose heights are present in the array
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        // Arrays to store the maximum height to the left and right of each
        // element
        vector<int> left(n, 0);
        vector<int> right(n, 0);

        // assigning this because for left[1] the max element to the left
        // element be the height of that element
        left[0] = height[0];
        // same reason as to why we assigned left[0] = height[0]
        right[n - 1] = height[n - 1];

        // Fill the left array with the maximum height to the left of each
        // element
        for (int i = 1; i < n - 1; i++)
            left[i] = max(left[i - 1], height[i]);

        // Fill the right array with the maximum height to the right of each
        // element
        for (int i = n - 2; i >= 1; i--)
            right[i] = max(right[i + 1], height[i]);

        // Calculate the trapped water
        for (int i = 1; i < n - 1; i++) {
            // Water can be trapped only if the current height is less than both
            // left and right heights
            if (height[i] < right[i] && height[i] < left[i]) {
                // The water level is determined by the shorter of the two walls
                // (left and right)
                water += min(left[i], right[i]) - height[i];
            }
        }
        return water;
    }
};