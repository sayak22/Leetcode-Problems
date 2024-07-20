class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size();  // Number of rows
        const int n = colSum.size();  // Number of columns
        vector<vector<int>> ans(m, vector<int>(n));  // Initialize the answer matrix

        // Iterate through each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Fill in the cell with the minimum of remaining row sum and column sum
                ans[i][j] = min(rowSum[i], colSum[j]);

                // Update the remaining row sum and column sum
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];
            }
        }

        return ans;  // Return the resulting matrix
    }
};
