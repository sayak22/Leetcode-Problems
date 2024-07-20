class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        const int m = rowSum.size();
        const int n = colSum.size();
        vector<vector<int>> ans(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // Skip if either rowSum[i] or colSum[j] is zero
                if (rowSum[i] == 0 || colSum[j] == 0)
                    continue;

                ans[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= ans[i][j];
                colSum[j] -= ans[i][j];

                // Early termination if both sums become zero
                if (rowSum[i] == 0 && colSum[j] == 0)
                    break;
            }
        }

        return ans;
    }
};
