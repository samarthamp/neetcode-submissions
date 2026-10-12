class Codec {
    
    void dfs_enc(TreeNode* root, string& encoded)
    {        
        if (!root) {encoded += "9999"; return;}

        string curr = to_string(root->val + 1000);
        encoded += string(4 - curr.length(), '0') + curr;

        dfs_enc(root->left, encoded);
        dfs_enc(root->right, encoded);

        return;
    }

    TreeNode* dfs_dec(const string& data, int& offset, int str_len)
    {
        if ((offset*4) >= str_len) return nullptr;
        string curr = data.substr(offset*4, 4);
        offset++;
        
        int root_val = stoi(curr) - 1000;
        if (root_val == 8999) return nullptr;

        TreeNode* root = new TreeNode(root_val);

        root->left = dfs_dec(data, offset, str_len);
        root->right = dfs_dec(data, offset, str_len);

        return root;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encoded = "";
        if (root) dfs_enc(root, encoded);
        return encoded;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.length() == 0) return nullptr;
        int offset = 0;
        int str_len = data.length();

        return dfs_dec(data, offset, str_len);
    }
};