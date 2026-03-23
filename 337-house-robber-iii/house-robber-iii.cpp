class Solution {
public:
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        int with_root = root->val + left.second + right.second;
        int without_root =
            max(left.first, left.second) + max(right.first, right.second);
        return {with_root, without_root};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};
