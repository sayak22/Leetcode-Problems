class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Initialize a vector to store the maximum probability for each node.
        vector<double> maxProb(n, 0.0);
        // Set the probability of starting node to 1 (since we're already there).
        maxProb[start_node] = 1.0;

        // We'll iterate at most n-1 times (Bellman-Ford algorithm).
        for (int i = 0; i < n - 1; ++i) {
            bool updated = false; // Keep track if any updates were made in this iteration.
            for (int j = 0; j < edges.size(); ++j) {
                int u = edges[j][0]; // Source node of the edge.
                int v = edges[j][1]; // Destination node of the edge.
                double prob = succProb[j]; // Probability of successfully traversing this edge.

                // Update the maximum probability for both nodes u and v.
                if (maxProb[u] * prob > maxProb[v]) {
                    maxProb[v] = maxProb[u] * prob;
                    updated = true;
                }
                if (maxProb[v] * prob > maxProb[u]) {
                    maxProb[u] = maxProb[v] * prob;
                    updated = true;
                }
            }
            // If no updates were made in this iteration, we can stop early.
            if (!updated) break;
        }

        // The final maximum probability for reaching the end_node.
        return maxProb[end_node];
    }
};
