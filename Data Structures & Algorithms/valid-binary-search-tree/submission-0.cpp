class Solution {
private:
    bool valid = true;
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        auto temp = dfs(root);
        return valid;
    }

    // call dfs() only with non-null root
    pair<int, int> dfs(TreeNode* root)
    {
        // {min, max}
        pair<int, int> left_val = {INT_MAX, INT_MIN};
        pair<int, int> right_val = {INT_MAX, INT_MIN};
        bool cond1 = false, cond2 = false;

        if (root->left) {left_val = dfs(root->left); cond1 = true;}
        if (root->right) {right_val = dfs(root->right); cond2 = true;}

        if (((left_val.second >= root->val) && cond1) || ((right_val.first <= root->val) && cond2)) valid = false;

        int curr_min = min({root->val, left_val.first, right_val.first});
        int curr_max = max({root->val, left_val.second, right_val.second});

        return {curr_min, curr_max};
    }
};