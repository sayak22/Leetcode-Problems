class Solution {
public:
// TC:O(N*log(N)) SC:O(N)
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Step 1: Create a vector of pairs to store (mappedValue, originalIndex)
        vector<pair<int, int>> storePairs;

        // Step 2: Iterate through each number in the 'nums' array
        for (int i = 0; i < nums.size(); ++i) {
            int mappedValue = 0; // Initialize the translated value for the current number
            int temp = nums[i]; // Store the current number in a temporary variable

            // Step 3: Translate the number based on the custom mapping
            // Start making changes from the units place.
            int place = 1; // Multiplier for constructing the translated number

            // If the value initially is 0, directly return mapping[0] and the index.
            if (temp == 0) {
                storePairs.push_back({mapping[0], i});
                continue; // Move to the next number
            }

            // Repeat the process for units, tenths, hundredths, and so on.
            while (temp != 0) {
                int digit = temp % 10; // Extract the last digit
                temp /= 10; // Move to the next digit
                mappedValue = place * mapping[digit] + mappedValue; // Add the mapped digit
                place *= 10; // Update the multiplier for the next digit position
            }

            // Store the (mappedValue, originalIndex) pair
            storePairs.push_back({mappedValue, i});
        }

        // Step 4: Sort the 'storePairs' array in non-decreasing order by the first value (default).
        sort(storePairs.begin(), storePairs.end());

        // Step 5: Create the final sorted answer array
        vector<int> answer;
        for (auto pair : storePairs) {
            answer.push_back(nums[pair.second]); // Retrieve the original number using the index
        }

        return answer; // Return the sorted array
    }
};
