class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Initialize the distance matrix with a large value (inf)
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize the diagonal elements to 0 (distance to itself)
        for (int i = 0; i < n; ++i)
            dist[i][i] = 0;

        // Populate the distance matrix with edge weights
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = dist[v][u] = w;
        }

        // Floyd-Warshall algorithm to find shortest distances
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        // Update the shortest distance if a shorter path exists
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int minNeighbors = INT_MAX;
        int resultCity = -1;

        // Check each city for reachable neighbors
        for (int i = 0; i < n; ++i) {
            int neighbors = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    // If the distance is within the threshold, increment neighbor count
                    ++neighbors;
                }
            }
            // Update the result if this city has fewer neighbors
            if (neighbors <= minNeighbors) {
                minNeighbors = neighbors;
                resultCity = i;
            }
        }

        // Return the city with the smallest number of neighbors
        return resultCity;
    }
};
