class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        auto [lo, hi] = minmax(p->val, q->val);
        auto it = root;

        while (true)
        {
            if ((it->val == lo) || (it->val == hi)) return it;
            if ((it->val > lo) && (it->val < hi)) return it;
            else if (it->val < lo) it = it->right;
            else it = it->left;
        }
        return nullptr;
    }
};