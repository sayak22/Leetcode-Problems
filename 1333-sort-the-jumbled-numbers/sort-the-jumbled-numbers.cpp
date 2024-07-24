class Solution {
public:
    // TC:O(N*log(N)) SC:O(N)
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Step 1: Define a helper function to translate an integer based on the custom mapping
        auto translate_integer = [&](int num) -> int {
            if (num == 0) {
                return mapping[0]; // Special case: map '0' directly
            }
            int res = 0;
            int cur_mult = 1; // Multiplier for constructing the translated number
            while (num > 0) {
                int digit = num % 10; // Extract the last digit
                num /= 10; // Move to the next digit
                res += mapping[digit] * cur_mult; // Add the mapped digit to the result
                cur_mult *= 10; // Update the multiplier for the next digit position
            }
            return res;
        };

        // Step 2: Create a map to store the translated values for each unique number
        unordered_map<int, int> number_mapping;
        for (int num : nums) {
            // If not already computed, translate the number and store it
            if (number_mapping.find(num) == number_mapping.end()) {
                number_mapping[num] = translate_integer(num);
            }
        }

        // Step 3: Sort the nums array using the custom mapping
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            return number_mapping[a] < number_mapping[b];
        });

        return nums;
    }
};
