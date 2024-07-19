class Solution {
public:
    // TC: O(N*M) [Iterating the matrix twice]
    // SC: O(N+M) [2 vectors of size N and M are used to store rowMin and colMax element]
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(); // Number of rows
        int n = matrix[0].size(); // Number of columns

        // Initialize vectors to store row minimums and column maximums
        vector<int> rowMin(m, INT_MAX);
        vector<int> colMax(n, INT_MIN);

        // Find row minimums
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }

        // Find column maximums
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }

        // Find the intersection of row minimums and column maximums
        vector<int> luckyNums;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    luckyNums.push_back(matrix[i][j]);
                }
            }
        }

        return luckyNums;
    }
};