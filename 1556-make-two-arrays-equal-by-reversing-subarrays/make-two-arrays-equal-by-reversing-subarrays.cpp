class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Check if 'arr' is a permutation of 'target'
        return std::is_permutation(arr.begin(), arr.end(), target.begin());
    }
};
