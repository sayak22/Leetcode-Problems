class Solution {
public:
    int minDifference(vector<int>& nums) {

        sort(nums.begin(),
             nums.end()); // sorting the array to get the indexes of the highest
                          // and lowest elements in the array
        // these are the 4 different operations that can be performed:-
        // Remove the last 3 elements.
        // Remove the first 3 elements.
        // Remove the first 1 and last 2 elements.
        // Remove the first 2 and last 1 elements.
        int minVal = INT_MAX; // stores the minimum difference value among all
                              // the 4 operations.

        int n = nums.size();

        // if the length of the array is less that 4, we remove 3 elements, 1
        // remains, diff=0
        if (n <= 4)
            return 0;

        // simulates if 3 elements have been removed from the back (3 highest
        // numbers removed from back)
        minVal = min(minVal, nums[n - 4] - nums[0]);

        // simulates if 2 elements have been removed from the back and 1 element
        // is removed from the front(the lowest element).
        minVal = min(minVal, nums[n - 3] - nums[1]);

        // simulates if 1 elements have been removed from the back and 2
        // elements are removed from the front(the lowest 2 element).
        minVal = min(minVal, nums[n - 2] - nums[2]);

        // simulates if 3 elements have been removed from the front (the lowest
        // 3 element).
        minVal = min(minVal, nums[n - 1] - nums[3]);

        return minVal;
    }
};