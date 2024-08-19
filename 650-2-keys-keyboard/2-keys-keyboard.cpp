class Solution {
public:
    int minSteps(int n) {
        if (n == 1) {
            // Base case: already have the desired string
            return 0;
        }
        
        int steps = 0;
        int factor = 2; // Start with the smallest prime factor
        
        while (n > 1) {
            while (n % factor == 0) {
                // While n is divisible by factor, copy factor characters
                steps += factor;
                n /= factor;
            }
            factor++; // Move to the next factor
        }
        
        return steps;
    }
};
