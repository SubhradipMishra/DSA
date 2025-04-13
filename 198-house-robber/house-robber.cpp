class Solution {
public:
    int f(int i, vector<int>& dp, vector<int>& a) {
        if (i == 0) return a[i];
        if (i < 0) return 0;

        if (dp[i] != -1) return dp[i];

        int pick = a[i] + f(i - 2, dp, a);      // Pick current, skip one
        int notPick = f(i - 1, dp, a);          // Don't pick current

        return dp[i] = max(pick, notPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(n - 1, dp, nums);  // Start from the last index
    }
};
