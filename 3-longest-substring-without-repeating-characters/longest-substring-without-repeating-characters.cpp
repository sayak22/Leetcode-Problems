class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) {
            return 1;
        }

        int maxLen = 0;
        // map of characters to their indices to store their occurance
        map<char, int> mp;
        int start = 0;

        for (int i = 0; i < s.length(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i;
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};