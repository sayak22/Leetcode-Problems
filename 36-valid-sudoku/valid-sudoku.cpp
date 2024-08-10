class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Initialize sets to keep track of seen digits in rows, columns, and boxes
        unordered_set<char> rowSet[9];
        unordered_set<char> colSet[9];
        unordered_set<char> boxSet[9];

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char curr = board[i][j];
                if (curr == '.') {
                    continue; // Skip empty cells
                }

            // Calculate the box index (0-8) based on row and column(draw and calculate for your own sake)
                int boxIdx = (i / 3) * 3 + j / 3;

                // Check row, column, and box for duplicate digits
                if (rowSet[i].count(curr) || colSet[j].count(curr) || boxSet[boxIdx].count(curr)) {
                    return false; // Duplicate found
                }

                // Add current digit to the corresponding sets
                rowSet[i].insert(curr);
                colSet[j].insert(curr);
                boxSet[boxIdx].insert(curr);
            }
        }

        return true; // No duplicates found
    }
};
