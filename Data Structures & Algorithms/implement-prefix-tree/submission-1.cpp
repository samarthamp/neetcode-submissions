class PrefixTree {
    struct TrieNode
    {
        vector<TrieNode*> arr;
        bool end;
        TrieNode() : arr(26, nullptr), end(false) {}
    };

    TrieNode* root;
public:
    PrefixTree() {
        root = new TrieNode();   
    }
    
    void insert(string word) {
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
        int n = word.length();

        auto it = root;
        for (int i = 0; i<n; i++)
        {
            int idx = word[i] - 'a';
            if (!it->arr[idx]) return false;
            
            it = it->arr[idx];
            if (i==n-1) return it->end;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        int n = prefix.length();

        auto it = root;
        for (int i = 0; i<n; i++)
        {
            int idx = prefix[i] - 'a';
            if (!it->arr[idx]) return false;
            
            it = it->arr[idx];
            if (i==n-1) return true;
        }
        return false;
    }
};