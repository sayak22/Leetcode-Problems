class Solution {
private:
    int connectedComponentCount = 0;  // Keeps track of the number of connected components

    // Helper function to find the representative (root) of a component
    int findRepresentative(int element, vector<int>& setRepresentatives) {
        if (setRepresentatives[element] == 0) {
            // If the element has no representative, assign itself as the representative
            setRepresentatives[element] = element;
            connectedComponentCount++;  // Increment the connected component count
        }
        // Path compression: Recursively find the representative and update the path
        return setRepresentatives[element] == element ? element :
               (setRepresentatives[element] = findRepresentative(setRepresentatives[element], setRepresentatives));
    }

    // Merge two components by updating their representatives
    void mergeComponents(int elementA, int elementB, vector<int>& setRepresentatives) {
        int repA = findRepresentative(elementA, setRepresentatives);
        int repB = findRepresentative(elementB, setRepresentatives);
        if (repA != repB) {
            // If the representatives are different, merge the components
            setRepresentatives[repB] = repA;
            connectedComponentCount--;  // Decrease the connected component count
        }
    }

public:
    int removeStones(vector<vector<int>>& stonePositions) {
        vector<int> setRepresentatives(20003, 0);  // Initialize the union-find data structure
        for (const auto& stonePosition : stonePositions) {
            // Merge stones in the same row or column
            mergeComponents(stonePosition[0] + 1, stonePosition[1] + 10002, setRepresentatives);
        }
        // The maximum number of stones that can be removed
        return stonePositions.size() - connectedComponentCount;
    }
};
