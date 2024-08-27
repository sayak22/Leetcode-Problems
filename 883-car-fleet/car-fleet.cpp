class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Combine position and speed into pairs for easier sorting.
        vector<pair<int, double>> cars;
        for (int i = 0; i < position.size(); ++i) {
            double timeToTarget = static_cast<double>(target - position[i]) / speed[i];
            cars.push_back({position[i], timeToTarget});
        }

        // Sort the cars based on their starting position (in descending order).
        sort(cars.begin(), cars.end(), greater<pair<int, double>>());

        int fleets = 0; // Number of fleets (groups of cars).
        double currFleetTime = 0.0; // Time taken by the current fleet.

        for (const auto& car : cars) {
            if (car.second > currFleetTime) {
                // This car cannot catch up with the previous fleet.
                // Form a new fleet with this car.
                currFleetTime = car.second;
                ++fleets;
            }
        }

        return fleets;
    }
};
