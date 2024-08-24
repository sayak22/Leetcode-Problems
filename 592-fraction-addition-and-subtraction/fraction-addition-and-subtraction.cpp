class Solution {
public:
// TC:O(N + log(deno)) SC:(O)
    string fractionAddition(string expression) {
        int nume = 0; // Numerator
        int deno = 1; // Denominator
        int i = 0;
        int n = expression.length();

        while (i < n) {
            int currNume = 0; // Current fraction numerator
            int currDeno = 0; // Current fraction denominator
            bool isNegative = (expression[i] == '-');

            // Skip '+' or '-'
            if (expression[i] == '+' || expression[i] == '-') {
                i++;
            }

            // Build the current numerator
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currNume = currNume * 10 + val;
                i++;
            }
            i++; // Skip the division character '/'

            if (isNegative) {
                currNume *= -1; // Apply negative sign if needed
            }

            // Build the current denominator
            while (i < n && isdigit(expression[i])) {
                int val = expression[i] - '0';
                currDeno = currDeno * 10 + val;
                i++;
            }

            // Update the accumulated numerator and denominator
            nume = nume * currDeno + currNume * deno;
            deno = deno * currDeno;
        }

        // Simplify the fraction using the greatest common divisor (GCD)
        int gcdd = gcd(abs(nume), deno);
        nume /= gcdd;
        deno /= gcdd;

        // Return the result in the form 'numerator/denominator'
        return to_string(nume) + "/" + to_string(deno);
    }

    // Helper function to calculate the GCD using the Euclidean Algorithm
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
};
