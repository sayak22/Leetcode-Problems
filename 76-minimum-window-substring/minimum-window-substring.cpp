class Solution {
public:
    string minWindow(string s, string t) {
        // Frequency map to count characters in 't'
        unordered_map<char, int> countMap;

        // Fill the map with the frequency of each character in 't'
        for (char ch : t)
            countMap[ch]++;

        // Initialize variables for the sliding window
        int left = 0, right = 0;
        int minLen = INT_MAX; // Variable to track the minimum window length
        int startIndex = -1;  // Starting index of the minimum window
        int count =0; // To count characters from 't' that match in the current window

        // Traverse the string 's' with the 'right' pointer
        while (right < s.length()) {
            // If current character is in 't', increment the matched count
            if (countMap[s[right]] > 0)
                count++;

            // Decrease the count of the current character in the map
            // This is to ensure that when the count is zero or negative, we
            // have extra or no need for this character
            countMap[s[right]]--;
            right++; // Expand the window to the right

            // When the count matches the length of 't', it means all characters
            // of 't' are included in the window
            while (count == t.length()) {
                // Update the minimum window length and start index
                if (right - left < minLen) {
                    minLen = right - left; // New minimum length found
                    startIndex = left; // Update start index of the minimum window
                }

                // Before contracting the window, increment the count of the
                // left character
                countMap[s[left]]++;

                // If the character is still in need (its count is positive),
                // decrement the matched count
                if (countMap[s[left]] > 0)
                    count--;

                // Move the left pointer to contract the window
                left++;
            }
        }

        // If startIndex is still -1, it means no valid window was found
        if (startIndex == -1)
            return "";

        // Return the minimum window substring from 's'
        return s.substr(startIndex, minLen);
    }
};
