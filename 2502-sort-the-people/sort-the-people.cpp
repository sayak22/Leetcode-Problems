class Solution {
public:
    vector<std::string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        unordered_map<int, string> mapping;

        // mapping heights to names in a hashmap to preserve the link of height and name
        for (int i = 0; i < n; ++i) {
            mapping[heights[i]] = names[i];
        }

        // Sorting in descending order 
        sort(heights.rbegin(), heights.rend());


        // Now reassigning name vector with the map values of each height.
        for (int i = 0; i < n; ++i) {
            names[i] = mapping[heights[i]];
        }

        return names;
    }
};