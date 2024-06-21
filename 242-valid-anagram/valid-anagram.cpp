class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map <char,int> mp;

        for(int i=0;i<s.length();i++) mp[s[i]]++;

        for(int i=0;i<t.length();i++) {
            if(mp[t[i]]>1) mp[t[i]]--;
            else mp.erase(t[i]);
        }
        if(mp.empty() && s.length()>=t.length()) return true;
        return false;
    }
};