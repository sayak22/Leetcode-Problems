class Solution {
public:

//:::::::::::::::::::
// Normal Approach:::
//:::::::::::::::::::
//   // TC: O(N) SC:O(N) n is the number of blocks whose heights are present in the array
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int water = 0;
//         // Arrays to store the maximum height to the left and right of each
//         // element
//         vector<int> left(n, 0);
//         vector<int> right(n, 0);

//         // assigning this because for left[1] the max element to the left
//         // element be the height of that element
//         left[0] = height[0];
//         // same reason as to why we assigned left[0] = height[0]
//         right[n - 1] = height[n - 1];

//         // Fill the left array with the maximum height to the left of each
//         // element
//         for (int i = 1; i < n - 1; i++)
//             left[i] = max(left[i - 1], height[i]);

//         // Fill the right array with the maximum height to the right of each
//         // element
//         for (int i = n - 2; i >= 1; i--)
//             right[i] = max(right[i + 1], height[i]);

//         // Calculate the trapped water
//         for (int i = 1; i < n - 1; i++) {
//             // Water can be trapped only if the current height is less than both
//             // left and right heights
//             if (height[i] < right[i] && height[i] < left[i]) {
//                 // The water level is determined by the shorter of the two walls
//                 // (left and right)
//                 water += min(left[i], right[i]) - height[i];
//             }
//         }
//         return water;
//     }

//::::::::::::::::::::::::::::::::::::::::
// 2 pointer approach (Space optimised):::
//::::::::::::::::::::::::::::::::::::::::
// TC: O(N) SC:O(1) N is the number of blocks whose heights are present in the array
   int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0; // If the array is empty, no water can be trapped

        // Initialize two pointers for traversing the array from both ends
        int left = 0, right = n - 1;
        // Variables to store the maximum heights encountered so far from the left and right
        int left_max = 0, right_max = 0;
        // Variable to store the total amount of trapped water
        int water = 0;

        // Traverse the array until the two pointers meet
        while (left <= right) {
            // If the height at the left pointer is less than or equal to the height at the right pointer
            if (height[left] <= height[right]) {
                // Update left_max if the current height is greater than or equal to left_max
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    // Calculate the trapped water at the left pointer
                    water += left_max - height[left];
                }
                // Move the left pointer to the right
                left++;
            } else {
                // If the height at the right pointer is less than the height at the left pointer
                // Update right_max if the current height is greater than or equal to right_max
                if (height[right] >= right_max) {
                    right_max = height[right];
                } else {
                    // Calculate the trapped water at the right pointer
                    water += right_max - height[right];
                }
                // Move the right pointer to the left
                right--;
            }
        }

        return water; // Return the total amount of trapped water
    }
};