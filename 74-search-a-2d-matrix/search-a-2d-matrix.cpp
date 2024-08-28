class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (target>= matrix[i][0]  and target <= matrix[i][matrix[i].size()-1]) {
                row = i;
                break;
            }
        }
        if (row == -1)
            return false;
        for (int j = 0; j < matrix[row].size(); j++)
            if (target == matrix[row][j])
                return true;

        return false;
    }
};