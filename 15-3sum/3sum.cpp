class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
               int target = 0;
        sort(nums.begin(), nums.end());
        // set<vector<int>> s;
        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;

            //skipping duplicate values of i
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;

                    while (j < k && nums[k] == nums[k + 1]) k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        // for(auto triplets : s)
        //     output.push_back(triplets);
        return output;
    }
};