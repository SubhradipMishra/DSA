class Solution {
public:
    void helper(map<int, int>& mp, TreeNode* root) {
        if (!root) return;
        helper(mp, root->left);
        mp[root->val]++;
        helper(mp, root->right);
    }

    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        helper(mp, root);

        for (auto x : mp) {
            int target = k - x.first;
            if (mp.find(target) != mp.end()) {
                if (target == x.first && mp[x.first] > 1) return true;
                if (target != x.first) return true;
            }
        }
        return false;
    }
};
