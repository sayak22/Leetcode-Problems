class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Base case: If the string length is 1, the entire string is the
        // longest substring without repetition.
        if (s.length() == 1) {
            return 1;
        }

        // Initialize variables:
        // - maxLen: Stores the maximum length of the substring found so far.
        // - mp: A map to store the last index of each character encountered.
        // - start: The starting index of the current substring.
        int maxLen = 0;
        map<char, int> mp;
        int start = 0;

        // Iterating through the string:
        for (int i = 0; i < s.length(); i++) {
            // Checking if the current character is already in the map and its last
            // index is greater than or equal to the current start. This
            // indicates that the character is already present within the
            // current substring.
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                // Update the start index to the index of the repeated character
                // plus 1 to exclude the repeated character from the current
                // substring.
                start = mp[s[i]] + 1;
            }

            // Update the last index of the current character in the map.
            mp[s[i]] = i;

            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};