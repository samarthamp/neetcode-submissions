class TrieNode {
public:
    vector<TrieNode*> arr;
    bool end;
    string word;
    TrieNode() : arr(26, nullptr), end(false), word("") {}

    void insert(string word) 
    {
        int n = word.length();

        auto it = this;
        for (int i = 0; i<n; i++)
        {
            int idx = word[i] - 'a';
            if (!it->arr[idx]) 
            {
                TrieNode* temp = new TrieNode();
                it->arr[idx] = temp; 
                it = temp;
            }
            
            else it = it->arr[idx];

            if (i==n-1) 
            {
                it->end = true;
                it->word = word;
            }
        }
    }
};

class Solution {
    int m, n;
    vector<string> ans;
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* root)
    {
        if ((i < 0) || (i >= m) || (j < 0) || (j >= n)
            || (board[i][j] == '*')) return;
        
        char c = board[i][j];
        if (!root->arr[c - 'a']) return;

        root = root->arr[c - 'a'];
        if (root->word != "")
        {
            ans.push_back(root->word);
            root->word = "";
        }

        board[i][j] = '*';
        dfs(board, i+1, j, root);
        dfs(board, i, j+1, root);
        dfs(board, i-1, j, root);
        dfs(board, i, j-1, root);
        board[i][j] = c;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        m = board.size();
        n = board[0].size();

        for (int i = 0; i < words.size(); i++) root->insert(words[i]);

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root);
            }
        }
        return ans;
    }
};