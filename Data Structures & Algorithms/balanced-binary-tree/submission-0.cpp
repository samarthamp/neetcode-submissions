class Solution {
private:
    bool cond = true;
public:
    bool isBalanced(TreeNode* root) {
        int temp = maxDepth(root);
        return cond;
    }

    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int left_len = maxDepth(root->left);
        int right_len = maxDepth(root->right);
        if (abs(left_len - right_len) > 1) cond = false;
        return max(left_len, right_len) + 1;
    }
};