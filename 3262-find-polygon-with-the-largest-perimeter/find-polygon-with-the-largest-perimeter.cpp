class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // sorting to get the largest sides
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (auto i : nums)
            sum += i;

        // We are starting considering that all the sides are taken into use.
        // we check if the largest side is less than the sum of the remaining or not, if yes we return the sum.
        // else we take that side out of the equation, and check for the 2nd highest side, untill that condition satisfies.
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (sum - nums[i] > nums[i]) {
                return sum;
            }
            sum = sum - nums[i];
        }
        return -1;
    }
};