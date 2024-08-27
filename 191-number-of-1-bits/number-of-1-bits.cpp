class Solution {
public:
    int hammingWeight(int n) {
        int count = 0; // Initialize a counter to keep track of the number of set bits (1s).

        while (n > 0) {
            n = (n & (n - 1)); // Clear the rightmost set bit (turn it to 0).
            count++; // Increment the count.
        }

        return count; // Return the total count of set bits.
    }
};
