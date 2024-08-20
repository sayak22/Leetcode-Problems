class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const int n = piles.size();
        vector<vector<int>> mem(n, vector<int>(n)); // Memoization table
        vector<int> suffix = piles; // suffix[i] := sum(piles[i..n))

        // Calculate the suffix sum (from right to left)
        for (int i = n - 2; i >= 0; --i)
            suffix[i] += suffix[i + 1];

        // Call the recursive function with initial state
        return stoneGameII(suffix, 0, 1, mem);
    }

private:
    // Returns the maximum number of stones Alice can get from piles[i..n) with M.
    int stoneGameII(const vector<int>& suffix, int i, int M, vector<vector<int>>& mem) {
        if (i + 2 * M >= mem.size())
            return suffix[i]; // If there are 2M or more piles remaining, take all remaining stones

        if (mem[i][M] > 0)
            return mem[i][M]; // Return cached result if available

        int opponent = suffix[i]; // Initialize opponent's score

        // Try all valid choices for X (from 1 to 2M)
        for (int X = 1; X <= 2 * M; ++X)
            opponent = min(opponent, stoneGameII(suffix, i + X, max(M, X), mem));

        // Store the result in the memoization table
        return mem[i][M] = suffix[i] - opponent;
    }
};
