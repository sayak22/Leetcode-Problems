class Solution {
public:
    // TC:O(N)
    static int minSwaps(vector<int>& nums) {
        // Get the size of the input vector nums
        const int n = nums.size();
        
        // Count the number of 1s in the input vector
        const int n1 = count(nums.begin(), nums.end(), 1);
        
        // Initialize the minimum swaps to a very large number (infinity)
        int mswap = INT_MAX;
        
        // Initialize a counter for the number of 1s in the current window
        int cnt1 = 0;

        // Use a sliding window approach with two pointers, l and r
        for (int l = 0, r = 0; r < n + n1; r++) {
            // Add the value at the current right pointer (modulus to wrap around)
            cnt1 += nums[r % n];
            
            // If the current window size exceeds the number of 1s (n1)
            // remove the value at the left pointer (modulus to wrap around)
            if (r - l + 1 > n1) 
                cnt1 -= nums[l++ % n];
            
            // When the window size is exactly the number of 1s (n1)
            // calculate the minimum swaps required to group all 1s together
            if (r - l + 1 == n1) 
                mswap = min(mswap, n1 - cnt1);
        }
        
        // Return the minimum swaps required
        return mswap;
    }
};

// Initialize I/O settings to make input and output faster
auto init = []() {
    // Turn off synchronization with C-style I/O
    ios::sync_with_stdio(0);
    // Untie cin from cout to make input faster
    cin.tie(0);
    // Untie cout from cin to make output faster
    cout.tie(0);
    // Return a character (not used) to complete the lambda
    return 'c';
}();
