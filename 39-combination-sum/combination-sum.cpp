class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, int target, vector<int>& candidates, vector<int>& ds) {
        if (index >= candidates.size()) {
            if (target == 0)
                ans.push_back(ds);
                return;
        }

        if (target >= candidates[index]) {
            ds.push_back(candidates[index]);
            solve(index, target - candidates[index], candidates, ds);
            ds.pop_back();
        }
        solve(index + 1, target, candidates, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds; // data structure to store the combinations
        solve(0, target, candidates, ds);
        return ans;
    }
};