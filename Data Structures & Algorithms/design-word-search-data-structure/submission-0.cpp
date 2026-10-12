class WordDictionary {
    struct TrieNode
    {
        vector<TrieNode*> arr;
        bool end;
        TrieNode() : arr(26, nullptr), end(false) {}
    };

    TrieNode* root;

    bool search2(TrieNode* curr_root, string& word) {
        int n = word.length();

        auto it = curr_root;
        for (int i = 0; i<n; i++)
        {
            if (word[i] != '.')
            {
                int idx = word[i] - 'a';
                if (!it->arr[idx]) return false;
                
                it = it->arr[idx];
                if (i==n-1) return it->end;
            }

            else
            {
                for (int idx = 0; idx < 26; idx++)
                {
                    auto it_any = it->arr[idx];
                    if (it_any && (i == n-1))
                    {
                        if (it_any->end) return true;
                        else continue;
                    }
                    
                    if (!it_any) continue;

                    string rest = word.substr(i+1);
                    
                    if (search2(it_any, rest)) return true;
                }
                return false;
            }
        }
        return false;
    }

public:
    WordDictionary() {
        root = new TrieNode();   
    }
    
    void addWord(string word) {
        int n = word.length();

        auto it = root;
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

            if (i==n-1) it->end = true;
        }
    }
    
    bool search(string word) {
        return search2(root, word);
    }
};