class Solution {
public:
    int nthUglyNumber(int n) {
        // Initialize an array to store ugly numbers.
        vector<int> arr(n + 1);

        // Create pointers for factors 2, 3, and 5.
        int i2, i3, i5;
        i2 = i3 = i5 = 1;

        // The first ugly number is always 1.
        arr[1] = 1;

        // Generate the remaining ugly numbers.
        for (int i = 2; i <= n; i++) {
            // Compute the potential ugly numbers by multiplying with factors.
            int i2ug = arr[i2] * 2;
            int i3ug = arr[i3] * 3;
            int i5ug = arr[i5] * 5;

            // Find the minimum of the three potential ugly numbers.
            int minug = min(i2ug, min(i3ug, i5ug));

            // Store the minimum as the next ugly number.
            arr[i] = minug;

            // Increment the pointers for the factors.
            if (minug == i2ug) i2++;
            if (minug == i3ug) i3++;
            if (minug == i5ug) i5++;
        }

        // Return the nth ugly number.
        return arr[n];
    }
};
