class Solution {
public:
    int minBitFlips(int start, int goal) {
        int xorResult =
            start ^ goal; // XOR gives 0 if they are the same number.
        int count = 0;

        while (xorResult > 0) {
            // this checks if the XOR of the last bits of the 2 numbers are same
            // or different, if different, count increased by 1.
            count += xorResult & 1;
            // checking the next bits by shifting the xorResult right by 1.
            xorResult >>= 1;
        }

        return count;
    }
};