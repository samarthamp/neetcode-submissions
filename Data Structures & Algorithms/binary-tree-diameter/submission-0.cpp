class Solution {
private:
    int max_dm = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        return max(dfs(root), max_dm) - 1;
    }

    int dfs(TreeNode* root)
    {
        if (!root) return 0;
        int left_len = dfs(root->left);
        int right_len = dfs(root->right);
        max_dm = max(max_dm, right_len + left_len + 1);

        return 1 + max(left_len, right_len);
    }
};