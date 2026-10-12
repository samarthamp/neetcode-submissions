class Solution {
    int max_path_sum = INT_MIN;

    int dfs(TreeNode* root)
    {
        int left_sum = 0;
        int right_sum = 0;

        if (root->left) left_sum = dfs(root->left);
        if (root->right) right_sum = dfs(root->right);

        max_path_sum = max({max_path_sum, root->val, root->val + left_sum, root->val + right_sum, root->val + left_sum + right_sum});

        return max({root->val, root->val + max(left_sum, right_sum)});
    }

public:
    int maxPathSum(TreeNode* root) {
        int temp = dfs(root);
        return max_path_sum;
    }   
};