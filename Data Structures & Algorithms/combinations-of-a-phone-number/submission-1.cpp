class Solution {
private:
    unordered_map<int, vector<char>> mp;
    vector<string> ans;
public:
    vector<string> letterCombinations(string digits) {
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        if (!digits.length()) return ans;
        string curr = "";
        dfs(digits, curr, 0);
        return ans;
    }

    void dfs(string digits, string& curr, int ptr)
    {
        if (ptr == digits.size()) {ans.push_back(curr); return;}

        string temp;
        temp[0] = digits[ptr];
        auto todo = mp[stoi(temp)];

        for (int i = 0; i < todo.size(); i++)
        {
            curr.push_back(todo[i]);
            dfs(digits, curr, ptr + 1);
            curr.pop_back();
        }
    }
};