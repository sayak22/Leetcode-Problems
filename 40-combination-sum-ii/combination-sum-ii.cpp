class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Sort the candidates to avoid duplicates in the final combinations.
        sort(candidates.begin(), candidates.end());

        // Create a vector to store the final combinations.
        vector<vector<int>> result;

        // Call the helper function to generate combinations.
        helper(candidates, target, 0, vector<int>(), result);

        return result;
    }

private:
    void helper(vector<int>& candidates, int target, int start, vector<int> current, vector<vector<int>>& result) {
        // If the target is reached, add the current combination to the result.
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Iterate over the candidates starting from the given index.
        for (int i = start; i < candidates.size(); i++) {
            // Skip duplicates to avoid redundant combinations.
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // If the current candidate is greater than the target, break the loop.
            if (candidates[i] > target) {
                break;
            }

            // Include the current candidate in the combination.
            current.push_back(candidates[i]);

            // Recursively call the helper function with the remaining target and updated start index.
            helper(candidates, target - candidates[i], i + 1, current, result);

            // Remove the current candidate from the combination.
            current.pop_back();
        }
    }
};