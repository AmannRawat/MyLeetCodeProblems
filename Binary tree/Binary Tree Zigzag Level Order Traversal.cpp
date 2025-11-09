class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        int chck = -1;
        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            chck++;
            for (int i = 0; i < size; i++) {
                TreeNode* n = q.front();
                q.pop();
                if (n->left != NULL)
                    q.push(n->left);
                if (n->right != NULL)
                    q.push(n->right);
                level.push_back(n->val);
            }
            if (chck % 2 == 0)
                ans.push_back(level);
            else {
                reverse(level.begin(), level.end());
                ans.push_back(level);
            }
        }
        return ans;
    }
};
