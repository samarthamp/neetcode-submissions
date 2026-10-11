class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> hash_s;
        unordered_map<int, int> hash_t;

        int len_s = s.length();
        int len_t = t.length();

        if (len_s != len_t) return false;

        for (auto i:s) hash_s[i - 'a']++;
        
        for (auto i:t) hash_t[i - 'a']++;

        for (int i =0; i<26; i++) if (hash_s[i] != hash_t[i]) return false;

        return true;
    }
};
