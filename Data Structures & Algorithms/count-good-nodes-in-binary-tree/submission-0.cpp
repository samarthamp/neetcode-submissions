class Solution {
public:
    int goodNodes(TreeNode* root) {
        int cnt = 1;
        if (root->left) cnt += dfs(root->left, root->val);
        if (root->right) cnt += dfs(root->right, root->val);

        return cnt;
    }

    int dfs(TreeNode* root, int limit)
    {
        int cnt1 = 0, cnt2 = 0;
        if (root->left) cnt1 = dfs(root->left, max(limit, root->val));
        if (root->right) cnt2 = dfs(root->right, max(limit, root->val));

        int ans = cnt1 + cnt2;
        if (root->val >= limit) ans++;
        return ans;
    }
};