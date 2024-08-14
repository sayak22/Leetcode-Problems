class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        // Step 1: Sort the input array
        sort(nums.begin(), nums.end());

        // Initialize the search range
        int low = 0;
        int high = nums.back() - nums.front();

        // Step 2: Binary search to find the kth smallest pair distance
        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check how many pairs have a distance less than or equal to 'mid'
            if (countPairs(nums, mid) < k) {
                low = mid + 1; // Adjust the lower bound
            } else {
                high = mid; // Adjust the upper bound
            }
        }

        // Step 3: Return the final result (the smallest distance that has at least k pairs)
        return low;
    }

private:
    // Helper function to count pairs with distance less than or equal to 'distance'
    int countPairs(const vector<int>& nums, int distance) {
        int count = 0;
        int left = 0;

        // Iterate through the array using two pointers (left and right)
        for (int right = 1; right < nums.size(); ++right) {
            // Move the left pointer until the distance between nums[right] and nums[left] is less than or equal to 'distance'
            while (nums[right] - nums[left] > distance) {
                ++left;
            }

            // Add the count of valid pairs within the current window
            count += right - left;
        }

        return count;
    }
};
