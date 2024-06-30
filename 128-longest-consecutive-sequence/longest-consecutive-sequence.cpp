class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int count = 1, maxCount = 0;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] == nums[i - 1] + 1)
                    count++;
                else {
                    maxCount = max(count, maxCount);
                    count = 1;
                }
            }
        }
        return max(count, maxCount);
    }
};