class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum,
                                      vector<int>& colSum) {
        const int m = rowSum.size(); // Number of rows
        const int n = colSum.size(); // Number of columns

        // Initialize an empty matrix (2D vector) with zeros
        vector<vector<int>> ans(m, vector<int>(n, 0));

        // Iterate through each cell in the matrix
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Calculate the value to place in the cell
                // It's the minimum of remaining row sum for row 'i' and
                // remaining column sum for column 'j'
                int value = min(rowSum[i], colSum[j]);

                // Update the cell value
                ans[i][j] = value;

                // Update remaining row sum and column sum
                rowSum[i] -= value;
                colSum[j] -= value;

                // If both rowSum[i] and colSum[j] become zero, terminate early
                // (Saves a bit more time)
                if (rowSum[i] == 0 && colSum[j] == 0)
                    break;
            }
        }

        // Return the filled-in matrix
        return ans;
    }
};
