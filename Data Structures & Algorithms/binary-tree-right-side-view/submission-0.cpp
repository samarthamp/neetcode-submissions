class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        auto it = root;
        queue<pair<TreeNode*, int>> q;

        vector<int> ans;
        if (!root) return ans;
        
        int level = 1;
        q.push({root, level});

        while (!q.empty())
        {
            vector<int> single_level;
            TreeNode* last;
            while (q.front().second == level)
            {
                pair<TreeNode*, int> x = q.front();
                q.pop();
                
                if (x.first->left) q.push({x.first->left, level+1});
                if (x.first->right) q.push({x.first->right, level+1});
                last = x.first;
            }
            level++;
            ans.push_back(last->val);
        }
        return ans;
    }
};