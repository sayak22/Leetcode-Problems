class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (auto i : nums)
            mp[i]++;

        vector<vector<int>> v(nums.size() + 1);

        for (auto i : mp)
            v[i.second].push_back(i.first);

        for (auto i = v.end(); i != v.begin();) {
            --i;
            for (auto j : *i) {
                ans.push_back(j);
                if (ans.size() == k)
                    return ans;
            }
        }
        return ans;
    }
};