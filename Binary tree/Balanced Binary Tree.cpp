class Solution {
public:
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;
        int lhs = solve(root->left);
        if (lhs == -1)
            return -1;

        int rhs = solve(root->right);
        if (rhs == -1)
            return -1;
        if (abs(lhs - rhs) > 1)
            return -1;
        return 1 + max(lhs, rhs);
    }
    bool isBalanced(TreeNode* root) { return solve(root) != -1; }
};