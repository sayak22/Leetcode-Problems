class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        if(strs.empty()) return ans;

        unordered_map<string, vector<string>> mapp; 
        for(string str: strs){
            string key = str;
            sort(key.begin(), key.end());
            mapp[key].push_back(str);
        }
        for(auto it: mapp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
