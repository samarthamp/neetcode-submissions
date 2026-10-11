#define all(v) (v).begin(), (v).end()

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;

        for (auto str:strs)
        {
            string key = str;
            sort(all(key));
            hashmap[key].push_back(str);
        }

        vector<vector<string>> res;
        for (auto it:hashmap) res.push_back(it.second);
        return res;
    }
};