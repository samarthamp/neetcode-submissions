class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        auto it = root;
        queue<pair<TreeNode*, int>> q;

        vector<vector<int>> ans;
        if (!root) return ans;
        
        int level = 1;
        q.push({root, level});

        while (!q.empty())
        {
            vector<int> single_level;

            while (q.front().second == level)
            {
                pair<TreeNode*, int> x = q.front();
                q.pop();
                single_level.push_back(x.first->val);
                if (x.first->left) q.push({x.first->left, level+1});
                if (x.first->right) q.push({x.first->right, level+1});
            }
            level++;
            ans.push_back(single_level);
        }
        return ans;
    }
};