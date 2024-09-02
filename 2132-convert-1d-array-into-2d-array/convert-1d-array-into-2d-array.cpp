class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        // If 1D array size is more than 2D array size we cannot store it.
        if (original.size() != m * n)
            return {};

        vector<vector<int>> ans(m, vector<int>(n, -1));

        // Observing the fact that i th element of original is stored at
        // ans[i/n][i%n], just traverse and store
        for (int i = 0; i < original.size(); i++)
            ans[i / n][i % n] = original[i];

        return ans;
    }
};