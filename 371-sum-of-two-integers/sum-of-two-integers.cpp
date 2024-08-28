class Solution {
public:
    int getSum(int a, int b) {
        // While there's still a carry (b != 0), continue the addition process.
        while (b != 0) {
            // Calculate the carry bits using AND.
            int carry = a & b;

            // Calculate the sum without considering carries using XOR.
            a = a ^ b;

            // Shift the carry bits to the left by one position.
            b = carry << 1;
        }

        // Return the final sum stored in a.
        return a;
    }
};