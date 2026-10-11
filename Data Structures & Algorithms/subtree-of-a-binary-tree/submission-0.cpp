class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!subRoot) return true;
        if (!root) return false;

        if (isSameTree(root, subRoot)) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p) && (!q)) return true;
        else if ((!p) || (!q)) return false;
        return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};