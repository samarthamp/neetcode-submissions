class Solution {
private:
    vector<vector<string>> ans;
    vector<string> curr;
public:
    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }

    void dfs(string s, int idx)
    {
        if (idx >= s.length()) 
        {
            vector<string> temp(curr);
            ans.push_back(temp);
            return;
        }

        for (int j = idx; j < s.length(); j++)
        {
            if (isPali(s, idx, j))
            {
                curr.push_back(s.substr(idx, j - idx + 1));
                dfs(s, j + 1);
                curr.pop_back();
            }
        }
        return;
    }

    bool isPali(string s, int left, int right)
    {
        while (left < right) 
        {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};