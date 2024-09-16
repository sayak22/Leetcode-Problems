class Solution {
public:
    int timeToMinutes(const string& time) {
        int hours =
            stoi(time.substr(0, 2)); // Extract hours and convert to integer
        int minutes =
            stoi(time.substr(3, 2)); // Extract minutes and convert to integer
        return hours * 60 + minutes; // Total minutes since midnight
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes; // Vector to store time points in minutes

        // Convert all time points to minutes and store in the vector
        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }

        // Sort the time points in ascending order
        sort(minutes.begin(), minutes.end());

        int minDiff = INT_MAX; // Initialize minimum difference to a large value
        int n = minutes.size(); // Number of time points

        // Calculate the differences between consecutive time points
        for (int i = 1; i < n; ++i) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }

        // Calculate the circular difference (difference between the last and
        // first time points)
        minDiff = min(minDiff, 1440 - minutes[n - 1] + minutes[0]);

        return minDiff; // Return the minimum difference found
    }
};