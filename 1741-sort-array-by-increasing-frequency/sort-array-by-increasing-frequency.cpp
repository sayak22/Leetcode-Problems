class Solution {
public:
    // TC:O(N) SC:O(N)
    vector<int> frequencySort(vector<int>& nums) {
        // Step 1: Create a frequency map
        unordered_map<int, int> freqMap;
        for (int num : nums) {
            freqMap[num]++;
        }
        
        // Step 2: Sort the array based on frequency and value
        sort(nums.begin(), nums.end(), [&] (int a, int b) {
            if (freqMap[a] == freqMap[b]) {
                return a > b; // Sort in increasing order if frequencies are equal
            }
            return freqMap[a] < freqMap[b]; // Sort by increasing frequency
        });
        
        // Step 3: Return the sorted array
        return nums;
    }
};
