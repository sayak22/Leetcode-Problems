class Solution {
public:
    vector<vector<int>> ans;

    void solve(int index, int target, vector<int>& candidates, vector<int>& ds) {
        if (index >= candidates.size()) {
            if (target == 0) // target = 0 means ds has one of the combination
                ans.push_back(ds);
                return;// returns, irrespective of whether target is 0 or not(preventing out of bounds problem)
        }

        // if the entire array isn't traversed yet, then we must make sure that cur element <= target
        if (target >= candidates[index]) {
            ds.push_back(candidates[index]);
            solve(index, target - candidates[index], candidates, ds);// deducting from target and considering the same element again, untill the target becomes less than that element.
            ds.pop_back(); // while backtracking from the decision tree, we need to remove the last element, as we are rejecting the current element and moving forward to the next element.
        }
        solve(index + 1, target, candidates, ds); // calling for the next element in the array.
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds; // data structure to store the combinations
        solve(0, target, candidates, ds);
        return ans;
    }
};