class Solution {
private:
    priority_queue<int> mx;
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return mx.top();
    }

    void dfs(TreeNode* root, int k)
    {
        if (!root) return;
        if (mx.size() < k) mx.push(root->val);
        else 
        {
            if (mx.top() > root->val)
            {
                mx.pop();
                mx.push(root->val);
            }
        }
        dfs(root->left, k);
        dfs(root->right, k);

        return;
    }
};