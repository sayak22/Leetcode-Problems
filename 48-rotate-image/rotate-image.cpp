class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // to rotate any 2D array by 90 degree, just do transpose and then mirror horizontally (reverse the collumns)

        
        // transposing the matrix
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                if (i > j)
                    swap(matrix[i][j], matrix[j][i]);


        // reversing the collumns 
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};